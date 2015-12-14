Gem::Specification.new do |s|
  s.name        = 'primesieve'
  s.version     = '1.1.0'
  s.date        = '2015-12-10'
  s.description = 'A wrapper for the primesieve C prime number generator'
  s.summary     = 'A wrapper for the primesieve lib'
  s.authors     = ['Robert Looby']
  s.email       = 'robertjlooby@gmail.com'
  s.files       = ['lib/primesieve.rb', 'ext/primesieve/primesieve-ruby.c', 'ext/primesieve/primesieve-ruby.h']
  s.extensions  = ['ext/primesieve/extconf.rb']
  s.homepage    = 'https://github.com/robertjlooby/primesieve-ruby'
  s.license     = 'MIT'
end
