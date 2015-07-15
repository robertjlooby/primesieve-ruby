require "mkmf"

LIBDIR     = RbConfig::CONFIG['libdir']
INCLUDEDIR = RbConfig::CONFIG['includedir']

HEADER_DIRS = [
  '/usr/local/include',
  INCLUDEDIR,
  '/usr/include',
]

LIB_DIRS = [
  '/usr/local/lib',
  LIBDIR,
  '/usr/lib',
]

dir_config('primesieve', HEADER_DIRS, LIB_DIRS)

fns = [
 'primesieve_generate_primes',
 'primesieve_generate_n_primes',
 'primesieve_nth_prime',
 'primesieve_parallel_nth_prime',
 'primesieve_count_primes',
 'primesieve_count_twins',
 'primesieve_count_triplets',
 'primesieve_count_quadruplets',
 'primesieve_count_quintuplets',
 'primesieve_count_sextuplets',
 'primesieve_parallel_count_primes',
 'primesieve_parallel_count_twins',
 'primesieve_parallel_count_triplets',
 'primesieve_parallel_count_quadruplets',
 'primesieve_parallel_count_quintuplets',
 'primesieve_parallel_count_sextuplets',
 'primesieve_print_primes',
 'primesieve_print_twins',
 'primesieve_print_triplets',
 'primesieve_print_quadruplets',
 'primesieve_print_quintuplets',
 'primesieve_print_sextuplets',
 'primesieve_callback_primes',
 'primesieve_parallel_callback_primes',
 'primesieve_get_sieve_size',
 'primesieve_get_num_threads',
 'primesieve_get_max_stop',
 'primesieve_set_sieve_size',
 'primesieve_set_num_threads',
 'primesieve_test'
]

unless find_header('primesieve.h')
  abort 'primesieve header is missing. please install primesieve'
end

fns.each do |fn|
  unless find_library('primesieve', fn)
    abort "primesieve library is missing. could not find function #{fn}. please install primesieve"
  end
end

create_makefile("primesieve/primesieve")
