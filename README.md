primesieve-ruby
===============
[![Gem Version](https://badge.fury.io/rb/primesieve.svg)](https://badge.fury.io/rb/primesieve)

Ruby bindings (gem wrapper) for the [primesieve C++ library](https://github.com/kimwalisch/primesieve). Generates primes orders of magnitude faster than any pure Ruby code.

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
syntax of the primesieve C++ library.

```Ruby
require 'primesieve'

# Generate an array of the primes in (0..19)
Primesieve.generate_primes(0, 19) #=> [2, 3, 5, 7, 11, 13, 17, 19]

# Generate an array of the first 5 primes starting at 11
Primesieve.generate_n_primes(5, 11) #=> [11, 13, 17, 19, 23]

# Get the 10th prime
Primesieve.nth_prime(10, 0) #=> 29

# Get the 1st prime after 10**18
Primesieve.nth_prime(1, 10**18) #=> 1000000000000000003

# Get the number of primes below 10**10
Primesieve.count_primes(0, 10**10) #=> 4118054813

# Get the upper limit of primesieve
Primesieve.get_max_stop #=> 18446744073709551615
```

Here is a [list of all available functions](ext/primesieve/extconf.rb).

How fast is it?
---------------

Starting with version 6.0, primesieve uses all CPU cores by default.

Ruby 2.7.2 [Prime](https://ruby-doc.org/stdlib-2.7.2/libdoc/prime/rdoc/Prime.html) module vs. primesieve to generate the first 10,000,000 primes:

```
           user     system      total        real
Ruby  15.015000   0.328000  15.343000 ( 15.350223)
gem    0.125000   0.032000   0.157000 (  0.157822)
```
