require 'rake'

begin
  require 'jeweler'
  Jeweler::Tasks.new do |s|
    s.name = "win32-serial"
    s.summary = "Ruby library for Windows API serial port communication based on http://grub.ath.cx/win32serial/"
    s.description = "Ruby library for Windows API serial port communication based on http://grub.ath.cx/win32serial/"
    s.email = "whitton@atlantic.net, jeff@socialrange.org"
    s.homepage = "http://grub.ath.cx/win32serial/"
    s.authors = ["Travis Whitton", "Jeff Rafter"]
    s.files =  FileList["[A-Z]*","{doc,examples,lib}/**/*", "ext/**/*.c", "ext/**/*.h"] 
    s.extensions << "ext/extconf.rb"
    s.require_paths = ["lib", "ext"]
  end
rescue LoadError
  puts "Jeweler not available. Install it with: sudo gem install technicalpickles-jeweler -s http://gems.github.com"
end


namespace :windows do
  desc "Make and package the windows version of compiled libraries"
  task :make do
    `cd ext && ruby -I . extconf.rb`
    `cd ext && make`
  end
  
  desc "Clean out the compiled libraries"
  task :clean do
    `cd ext && make clean`
  end
  
  desc "Generate a gemspec for a Windows binary distribution"
  task :gemspec do
    ext = "SPEC.platform = ::Gem::Platform.new('i386-mswin32_60'); SPEC.extensions = []; SPEC.files +=  ['ext/Win32Serial.so']"
    `cp win32-serial.gemspec win32-serial.gemspec.windows`
    `echo "#{ext}" >> win32-serial.gemspec.windows`    
  end
  
  desc "Package the Windows gem as a binary release"
  task :release do
    `gem build win32-serial.gemspec.windows`
    `mv *.gem bin`
  end
end
