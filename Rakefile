require 'rake'

begin
  require 'jeweler'
  Jeweler::Tasks.new do |s|
    s.name = "win32serial"
    s.summary = "Ruby library for Windows API serial port communication"
    s.description = "Ruby library for Windows API serial port communication calls based on http://grub.ath.cx/win32serial/"
    s.email = "whitton@atlantic.net, jeff@socialrange.org"
    s.homepage = "http://grub.ath.cx/win32serial/"
    s.authors = ["Travis Whitton", "Jeff Rafter"]
    s.files =  FileList["[A-Z]*"] 
    s.extensions << 'extconf.rb'
  end
rescue LoadError
  puts "Jeweler not available. Install it with: sudo gem install technicalpickles-jeweler -s http://gems.github.com"
end


namespace :windows do
  desc "Build and package the windows version of the gem"
  task :build do
    `cd ext && ruby -I . extconf.rb`
    `make`
  end
end
