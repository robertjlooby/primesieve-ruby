#include <primesieve-ruby.h>

VALUE mPrimesieve;

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

void Init_primesieve() {
  mPrimesieve = rb_define_module("Primesieve");

  rb_define_module_function(mPrimesieve, "generate_primes", generate_primes, 2);
  rb_define_module_function(mPrimesieve, "generate_n_primes", generate_n_primes, 2);
  rb_define_module_function(mPrimesieve, "nth_prime", nth_prime, 2);
  rb_define_module_function(mPrimesieve, "count_primes", count_primes, 2);
  rb_define_module_function(mPrimesieve, "count_twins", count_twins, 2);
  rb_define_module_function(mPrimesieve, "count_triplets", count_triplets, 2);
  rb_define_module_function(mPrimesieve, "count_quadruplets", count_quadruplets, 2);
  rb_define_module_function(mPrimesieve, "count_quintuplets", count_quintuplets, 2);
  rb_define_module_function(mPrimesieve, "count_sextuplets", count_sextuplets, 2);
  rb_define_module_function(mPrimesieve, "print_primes", print_primes, 2);
  rb_define_module_function(mPrimesieve, "print_twins", print_twins, 2);
  rb_define_module_function(mPrimesieve, "print_triplets", print_triplets, 2);
  rb_define_module_function(mPrimesieve, "print_quadruplets", print_quadruplets, 2);
  rb_define_module_function(mPrimesieve, "print_quintuplets", print_quintuplets, 2);
  rb_define_module_function(mPrimesieve, "print_sextuplets", print_sextuplets, 2);
  rb_define_module_function(mPrimesieve, "get_sieve_size", get_sieve_size, 0);
  rb_define_module_function(mPrimesieve, "get_num_threads", get_num_threads, 0);
  rb_define_module_function(mPrimesieve, "get_max_stop", get_max_stop, 0);
  rb_define_module_function(mPrimesieve, "set_sieve_size", set_sieve_size, 1);
  rb_define_module_function(mPrimesieve, "set_num_threads", set_num_threads, 1);
}
