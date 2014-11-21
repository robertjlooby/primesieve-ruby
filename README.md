prime_sieve
==========
[![Gem Version](https://badge.fury.io/rb/prime_sieve.svg)](http://badge.fury.io/rb/prime_sieve)

prime_sieve is a gem wrapper for the [primesieve](http://primesieve.org/) prime number generator

Installing
==========
* Get primesieve
  * On OSX: `brew install primesieve`
  * [download here](http://primesieve.org/downloads/)
  * [follow instructions to build from source](http://primesieve.org/build.html)

* Get the prime_sieve gem
  * `gem install prime_sieve`
-or-
  * add `gem 'prime_sieve'` to your Gemfile and run `bundle install`

Usage
=====
First `require 'prime_sieve'`
Then you have access to the `PrimeSieve` module which has all the functions of primesieve documented [here](http://primesieve.org/api/primesieve_8h.html) with the following exceptions:
* functions requiring a type cannot be passed a type and will default to `UINT64_PRIMES`
* functions requiring a `size_t *` cannot be passed that arg (an appropriatly sized Ruby array will be returned)
* the function names leave off the `primesieve_` prefix
  * for example, to call `primesieve_generate_primes`, use `PrimeSieve.generate_primes(start, stop)`
* the functions `callback_primes` and `parallel_callback_primes` take a block rather than a callback function
* `primesieve_free` is not implemented

But how fast is it?
===================
Ruby 2.1.3 [Prime](http://www.ruby-doc.org/stdlib-2.0.0/libdoc/prime/rdoc/Prime.html) module vs. prime_sieve to generate the first 10,000,000 primes
```
           user     system      total        real
Ruby  26.680000   3.930000  30.610000 ( 30.621654)
gem    0.290000   0.070000   0.360000 (  0.361699)
```
