#include <prime_sieve.h>

VALUE mPrimeSieve;

static VALUE generate_primes(VALUE self, VALUE start, VALUE stop) {
  size_t size, i;
  uint64_t* primes = (uint64_t *) primesieve_generate_primes(NUM2ULL(start), NUM2ULL(stop), &size, UINT64_PRIMES);
  VALUE ruby_primes = rb_ary_new2(size);
  for(i = 0; i < size; i++) {
    rb_ary_store(ruby_primes, i, ULL2NUM(primes[i]));
  }
  primesieve_free(primes);
  return ruby_primes;
}

static VALUE generate_n_primes(VALUE self, VALUE n, VALUE start) {
  long i;
  uint64_t* primes = (uint64_t *) primesieve_generate_n_primes(NUM2ULL(n), NUM2ULL(start), UINT64_PRIMES);
  VALUE ruby_primes = rb_ary_new2(NUM2LONG(n));
  for(i = 0; i < NUM2LONG(n); i++) {
    rb_ary_store(ruby_primes, i, ULL2NUM(primes[i]));
  }
  primesieve_free(primes);
  return ruby_primes;
}

static VALUE nth_prime(VALUE self, VALUE n, VALUE start) {
  return ULL2NUM(primesieve_nth_prime(NUM2LL(n), NUM2ULL(start)));
}

static VALUE parallel_nth_prime(VALUE self, VALUE n, VALUE start) {
  return ULL2NUM(primesieve_parallel_nth_prime(NUM2LL(n), NUM2ULL(start)));
}

static VALUE count_primes(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_count_primes(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE count_twins(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_count_twins(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE count_triplets(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_count_triplets(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE count_quadruplets(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_count_quadruplets(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE count_quintuplets(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_count_quintuplets(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE count_sextuplets(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_count_sextuplets(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE parallel_count_primes(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_parallel_count_primes(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE parallel_count_twins(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_parallel_count_twins(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE parallel_count_triplets(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_parallel_count_triplets(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE parallel_count_quadruplets(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_parallel_count_quadruplets(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE parallel_count_quintuplets(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_parallel_count_quintuplets(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE parallel_count_sextuplets(VALUE self, VALUE start, VALUE stop) {
  return ULL2NUM(primesieve_parallel_count_sextuplets(NUM2ULL(start), NUM2ULL(stop)));
}

static VALUE print_primes(VALUE self, VALUE start, VALUE stop) {
  primesieve_print_primes(NUM2ULL(start), NUM2ULL(stop));
  return Qnil;
}

static VALUE print_twins(VALUE self, VALUE start, VALUE stop) {
  primesieve_print_twins(NUM2ULL(start), NUM2ULL(stop));
  return Qnil;
}

static VALUE print_triplets(VALUE self, VALUE start, VALUE stop) {
  primesieve_print_triplets(NUM2ULL(start), NUM2ULL(stop));
  return Qnil;
}

static VALUE print_quadruplets(VALUE self, VALUE start, VALUE stop) {
  primesieve_print_quadruplets(NUM2ULL(start), NUM2ULL(stop));
  return Qnil;
}

static VALUE print_quintuplets(VALUE self, VALUE start, VALUE stop) {
  primesieve_print_quintuplets(NUM2ULL(start), NUM2ULL(stop));
  return Qnil;
}

static VALUE print_sextuplets(VALUE self, VALUE start, VALUE stop) {
  primesieve_print_sextuplets(NUM2ULL(start), NUM2ULL(stop));
  return Qnil;
}

static void callback_fn(uint64_t prime) {
  rb_yield(ULL2NUM(prime));
  return;
}

static VALUE callback_primes(VALUE self, VALUE start, VALUE stop) {
  if (!rb_block_given_p())
    rb_raise(rb_eArgError, "Expected block");
  primesieve_callback_primes(NUM2ULL(start), NUM2ULL(stop), callback_fn);
  return Qnil;
}

static void parallel_callback_fn(uint64_t prime, int thread_id) {
  rb_yield_values(2, ULL2NUM(prime), INT2NUM(thread_id));
  return;
}

static VALUE parallel_callback_primes(VALUE self, VALUE start, VALUE stop) {
  if (!rb_block_given_p())
    rb_raise(rb_eArgError, "Expected block");
  primesieve_parallel_callback_primes(NUM2ULL(start), NUM2ULL(stop), parallel_callback_fn);
  return Qnil;
}

static VALUE get_sieve_size(VALUE self) {
  return INT2NUM(primesieve_get_sieve_size());
}

static VALUE get_num_threads(VALUE self) {
  return INT2NUM(primesieve_get_num_threads());
}

static VALUE get_max_stop(VALUE self) {
  return ULL2NUM(primesieve_get_max_stop());
}

static VALUE set_sieve_size(VALUE self, VALUE sieve_size) {
  primesieve_set_sieve_size(NUM2INT(sieve_size));
  return Qnil;
}

static VALUE set_num_threads(VALUE self, VALUE num_threads) {
  primesieve_set_num_threads(NUM2INT(num_threads));
  return Qnil;
}

static VALUE test(VALUE self) {
  return INT2NUM(primesieve_test());
}

void Init_prime_sieve() {
  mPrimeSieve = rb_define_module("PrimeSieve");

  rb_define_module_function(mPrimeSieve, "generate_primes", generate_primes, 2);
  rb_define_module_function(mPrimeSieve, "generate_n_primes", generate_n_primes, 2);
  rb_define_module_function(mPrimeSieve, "nth_prime", nth_prime, 2);
  rb_define_module_function(mPrimeSieve, "parallel_nth_prime", parallel_nth_prime, 2);
  rb_define_module_function(mPrimeSieve, "count_primes", count_primes, 2);
  rb_define_module_function(mPrimeSieve, "count_twins", count_twins, 2);
  rb_define_module_function(mPrimeSieve, "count_triplets", count_triplets, 2);
  rb_define_module_function(mPrimeSieve, "count_quadruplets", count_quadruplets, 2);
  rb_define_module_function(mPrimeSieve, "count_quintuplets", count_quintuplets, 2);
  rb_define_module_function(mPrimeSieve, "count_sextuplets", count_sextuplets, 2);
  rb_define_module_function(mPrimeSieve, "parallel_count_primes", parallel_count_primes, 2);
  rb_define_module_function(mPrimeSieve, "parallel_count_twins", parallel_count_twins, 2);
  rb_define_module_function(mPrimeSieve, "parallel_count_triplets", parallel_count_triplets, 2);
  rb_define_module_function(mPrimeSieve, "parallel_count_quadruplets", parallel_count_quadruplets, 2);
  rb_define_module_function(mPrimeSieve, "parallel_count_quintuplets", parallel_count_quintuplets, 2);
  rb_define_module_function(mPrimeSieve, "parallel_count_sextuplets", parallel_count_sextuplets, 2);
  rb_define_module_function(mPrimeSieve, "print_primes", print_primes, 2);
  rb_define_module_function(mPrimeSieve, "print_twins", print_twins, 2);
  rb_define_module_function(mPrimeSieve, "print_triplets", print_triplets, 2);
  rb_define_module_function(mPrimeSieve, "print_quadruplets", print_quadruplets, 2);
  rb_define_module_function(mPrimeSieve, "print_quintuplets", print_quintuplets, 2);
  rb_define_module_function(mPrimeSieve, "print_sextuplets", print_sextuplets, 2);
  rb_define_module_function(mPrimeSieve, "callback_primes", callback_primes, 2);
  rb_define_module_function(mPrimeSieve, "parallel_callback_primes", parallel_callback_primes, 2);
  rb_define_module_function(mPrimeSieve, "get_sieve_size", get_sieve_size, 0);
  rb_define_module_function(mPrimeSieve, "get_num_threads", get_num_threads, 0);
  rb_define_module_function(mPrimeSieve, "get_max_stop", get_max_stop, 0);
  rb_define_module_function(mPrimeSieve, "set_sieve_size", set_sieve_size, 1);
  rb_define_module_function(mPrimeSieve, "set_num_threads", set_num_threads, 1);
  rb_define_module_function(mPrimeSieve, "test", test, 0);
}
