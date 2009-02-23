require '../Win32Serial'

raise "USAGE: modem.rb <COMPORT>" if !ARGV[0]
port = ARGV[0]
s = Win32Serial.new
s.open(port)
s.config(9600, 8, Win32Serial::NOPARITY, Win32Serial::ONESTOPBIT)
s.timeouts(0, 200, 0, 0, 0)
bytes = s.write("ATD\r")
puts "#{bytes} bytes written to COM2"
puts "response " + s.read(14)
s.close
