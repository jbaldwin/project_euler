#include <stdio.h>
#include <math.h>

#include "../lib/prime.h"

#define LIMIT 2000000

typedef unsigned long long i64;

int main(int argc, char* argv[]) {
	
	sieve_t sieve = prime_sieve(LIMIT);

	i64 total = 0;
	for(int i = 0; i < sieve.num; i++) {
			total += sieve.primes[i];
	}
	
	printf("%llu", total);

	return 0;
}

