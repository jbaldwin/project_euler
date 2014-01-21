#include <stdio.h>
#include <math.h>

#include "../lib/prime.h"

#define LIMIT 2000000

int main(int argc, char* argv[]) {
	
	unsigned int num_primes;
	unsigned int* primes = prime_sieve(LIMIT, &num_primes);

	unsigned long long total = 0;
	for(int i = 0; i < num_primes; i++) {
			total += primes[i];
	}
	
	printf("%llu\n", total);

	return 0;
}
