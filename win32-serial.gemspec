# -*- encoding: utf-8 -*-

SPEC = Gem::Specification.new do |s|
  s.name = %q{win32-serial}
  s.version = "0.5.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Travis Whitton", "Jeff Rafter"]
  s.date = %q{2009-02-23}
  s.description = %q{Ruby library for Windows API serial port communication based on http://grub.ath.cx/win32serial/}
  s.email = %q{whitton@atlantic.net, jeff@socialrange.org}
  s.extensions = ["ext/extconf.rb"]
  s.files = ["Changelog", "GPL", "Rakefile", "README", "VERSION.yml", "doc/win32serial.rd", "examples/modem.rb", "lib/serialport.rb", "ext/rb_serial.c", "ext/serial.c", "ext/serial.h", "ext/extconf.rb"]
  s.homepage = %q{http://grub.ath.cx/win32serial/}
  s.require_paths = ["lib", "ext"]
  s.rubygems_version = %q{1.3.1}
  s.summary = %q{Ruby library for Windows API serial port communication based on http://grub.ath.cx/win32serial/}

  if s.respond_to? :specification_version then
    current_version = Gem::Specification::CURRENT_SPECIFICATION_VERSION
    s.specification_version = 2

    if Gem::Version.new(Gem::RubyGemsVersion) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
