Gem::Specification.new do |s|
  s.name        = 'prime_sieve'
  s.version     = '0.0.2'
  s.date        = '2014-11-21'
  s.description = 'A wrapper for the primesieve C prime number generator'
  s.summary     = 'A wrapper for the primesieve lib'
  s.authors     = ['Robert Looby']
  s.email       = 'robertjlooby@gmail.com'
  s.files       = ['lib/prime_sieve.rb', 'ext/prime_sieve/prime_sieve.c', 'ext/prime_sieve/prime_sieve.h']
  s.extensions  = ['ext/prime_sieve/extconf.rb']
  s.homepage    = 'https://github.com/robertjlooby/prime_sieve'
  s.license     = 'MIT'
end
