prime_sieve
==========

prime_sieve is a gem wrapper for the primesieve prime number generator

Installing
==========
* Get primesieve
** On OSX: `brew install primesieve`
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
