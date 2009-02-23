require 'Win32Serial'

# Simple Win32Serial wrapper intended to achieve compatibility with other
# serial port implementions (including ruby-serialport). Limited functionality
# is available at the moment. An application should not use this implmentation
# with other implementations simultaneously.
class SerialPort

  NONE = 1
  EVEN = 2
  ODD = 3
  MARK = 4
  SPACE = 5

  # Creates a serial port object.
  #
  # <tt>port</tt> may be a port number or the name of a device. The number is 
  # portable; so 0 is mapped to "COM1" and so on.
  #
  # <tt>params</tt> can be used to configure the serial port. See 
  # SerialPort#set_modem_params for details
  def initialize(port, *params)    
    @port = port
    @port = "COM#{port+1}" if port.is_a? Integer
    @serial = Win32Serial.new
    @serial.open(port)
    begin
      config(*params)
    rescue
      close
      raise
    end
  end

  # This behaves like SerialPort#new, except that you can pass a block
  # to which the new serial port object will be passed. In this case
  # the connection is automaticaly closed when the block has finished.
  def self.open(port, *params)
    sp = SerialPort.new(port, params)
    begin
      if (block_given?)
        yield sp
        sp.close
        return nil
      end
    rescue
      sp.close
      raise
    end
    sp
  end
  
  def close
    @serial.close
  end
  
  def config(baud_rate, data_bits, stop_bits, parity)
    baud_rate = case baud_rate
      when 110
        Win32Serial::CBR_110
      when 300
        Win32Serial::CBR_300
      when 600
        Win32Serial::CBR_600
      when 1200
        Win32Serial::CBR_1200
      when 2400
        Win32Serial::CBR_2400
      when 4800
        Win32Serial::CBR_4800
      when 9600
        Win32Serial::CBR_9600
      when 14400
        Win32Serial::CBR_14400
      when 19200
        Win32Serial::CBR_19200
      when 38400
        Win32Serial::CBR_38400
      when 56000
        Win32Serial::CBR_56000
      when 57600
        Win32Serial::CBR_57600
      when 115200
        Win32Serial::CBR_115200
      when 128000
        Win32Serial::CBR_128000
      when 256000
        Win32Serial::CBR_256000
      else
        nil
    end

    stop_bits = case stop_bits
      when 1
        Win32Serial::ONESTOPBIT
      when 1.5
        Win32Serial::ONE5STOPBITS
      when 2
        Win32Serial::TWOSTOPBITS
    end
        
    parity = case parity
      when NONE
        Win32Serial::NOPARITY
      when EVEN
        Win32Serial::EVENPARITY
      when ODD
        Win32Serial::ODDPARITY
      when MARK
        Win32Serial::MARKPARITY
      when SPACE
        Win32Serial::SPACEPARITY
    end      
  
    # TODO move the timeout code to separate attributes
    @serial.config(baud_rate, data_bits, parity, stop_bits)    
    @serial.timeouts(0, 200, 0, 0, 0)
  end
  
  def write(buf)
    count = @serial.write(buf)
    raise Errno::EIO.new("Could not write the data to the port") unless count
    count
  end
  
  # Read a specific number of bytes
  def read(count)
    @serial.read(count)
  end

  def putc(c)
    write(c)
  end
  
  # Blocking in general is not specificly implemented. So we poll for the 
  # characters which is not expressly bad when working at 9600 baud
  def getc
    c = read(1)
    c ? c[0] : nil
  end  
  
end
