primesieve-ruby
===============
[![Gem Version](https://badge.fury.io/rb/primesieve.svg)](http://badge.fury.io/rb/primesieve)

Ruby bindings for the primesieve C/C++ library. Generates primes orders of magnitude faster than any pure Ruby code.  Features:

* Generate a list of primes
* Count primes and [prime k-tuplets](https://en.wikipedia.org/wiki/Prime_k-tuple)
* Print primes and prime k-tuplets
* Find the nth prime

Installing
----------

* Get primesieve
  * __OS X:__ `brew install primesieve`
  * [Build from source](https://github.com/kimwalisch/primesieve#build-instructions-unix-like-oses)

* Get the primesieve gem
  * `gem install primesieve`
__-or-__
  * add `gem 'primesieve'` to your Gemfile and run `bundle install`

Usage
-----

The syntax of the primesieve Ruby bindings is nearly identical to the
syntax of the primesieve C library.

```Ruby
require 'primesieve'

# Generate an array with the primes inside [0, 20]
primes = Primesieve.generate_primes(0, 20)

# Generate an array of the first 10 primes starting at 0
primes = Primesieve.generate_n_primes(10, 0)

# Get the 10th prime
puts Primesieve.nth_prime(10, 0);

# Count the primes below 10**9
puts Primesieve.count_primes(0, 10**9)
```

Here is a [list of all available functions](ext/primesieve/extconf.rb).

Multi-threading
---------------

Counting primes and prime k-tuplets and finding the nth prime can be done in parallel using multiple threads, just use the ```parallel_``` prefix and primesieve will use all your CPU cores.

```Ruby
require 'primesieve'

# Count the primes below 10**11 using all CPU cores
puts Primesieve.parallel_count_primes(0, 10**11)

# Find the 10**10th prime (starting at 0) using all CPU cores
puts Primesieve.parallel_nth_prime(10**10, 0)
```

How fast is it?
---------------

Ruby 2.1.3 [Prime](http://www.ruby-doc.org/stdlib-2.0.0/libdoc/prime/rdoc/Prime.html) module vs. primesieve to generate the first 10,000,000 primes.

```
           user     system      total        real
Ruby  26.680000   3.930000  30.610000 ( 30.621654)
gem    0.290000   0.070000   0.360000 (  0.361699)
```
