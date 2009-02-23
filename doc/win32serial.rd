=begin
= Win32Serial extension module

== Win32Serial
=== Constants
: CBR_110
     Baud Rate
: CBR_300
     Baud Rate
: CBR_600
     Baud Rate
: CBR_1200
     Baud Rate
: CBR_2400
     Baud Rate
: CBR_4800
     Baud Rate
: CBR_9600
     Baud Rate
: CBR_14400
     Baud Rate
: CBR_19200
     Baud Rate
: CBR_38400
     Baud Rate
: CBR_56000
     Baud Rate
: CBR_57600
     Baud Rate
: CBR_115200
     Baud Rate
: CBR_128000
     Baud Rate
: CBR_256000
     Baud Rate

: NOPARITY
     Parity setting
: ODDPARITY
     Parity setting
: EVENPARITY
     Parity setting
: MARKPARITY
     Parity setting
: SPACEPARITY
     Parity setting

: ONESTOPBIT
     Stop bit setting
: ONE5STOPBITS
     Stop bit setting
: TWOSTOPBITS
     Stop bit setting

=== Method
: open(comport)
    opens the specified comport. (returns nil on error)
: config(baudrate, bytesize, parity, stopbits)
    configures the port to the appropriate settings. (returns nil on error)
: timeouts(read_interval, read_mult, read_const, write_mult, write_const)
    sets timeout for reads and writes. (returns nil on error)
: read(n)
    reads n bytes from port. (returns nil on error)
: writeport(data)
    writes data to port. (returns nil on error)
: cleanup
    closes down the connection. (returns nil on error)
