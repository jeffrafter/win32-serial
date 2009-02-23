require 'Win32Serial'

raise "USAGE: modem.rb <COMPORT>" if !ARGV[0]
port = ARGV[0]
s = Win32Serial.new
s.open(port)
s.config(9600, 8, Win32Serial::NOPARITY, Win32Serial::ONESTOPBIT)
s.timeouts(0, 200, 0, 0, 0)
bytes = s.write("AT+CGMI\r") || "< no bytes >"
puts "#{bytes} bytes written to #{port}"
puts "response " + (s.read(14) || " < no response >")
s.close