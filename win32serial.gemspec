# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{win32serial}
  s.version = "0.0.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Travis Whitton", "Jeff Rafter"]
  s.date = %q{2009-02-22}
  s.description = %q{Ruby library for Windows API serial port communication calls based on http://grub.ath.cx/win32serial/}
  s.email = %q{whitton@atlantic.net, jeff@socialrange.org}
  s.extensions = ["extconf.rb"]
  s.files = ["Changelog", "GPL", "Makefile", "Rakefile", "README", "VERSION.yml", "extconf.rb"]
  s.homepage = %q{http://grub.ath.cx/win32serial/}
  s.require_paths = ["lib"]
  s.rubygems_version = %q{1.3.1}
  s.summary = %q{Ruby library for Windows API serial port communication}

  if s.respond_to? :specification_version then
    current_version = Gem::Specification::CURRENT_SPECIFICATION_VERSION
    s.specification_version = 2

    if Gem::Version.new(Gem::RubyGemsVersion) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
