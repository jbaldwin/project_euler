#include <stdio.h>
#include <math.h>

#include "../lib/prime.h"

#define LIMIT 2000000

int main(int argc, char* argv[]) {
	
/*	int sievebound = (LIMIT - 1) / 2;
	char sieve[sievebound];
	for(int i = 1; i < sievebound; i++) {
		sieve[i] = 1;
	}
	int crosslimit = (int)floor(sqrt((double)sievebound));

	for(int i = 1; i < crosslimit; i++) {
		if(sieve[i] == 1) {
			for(int j = 2 * i * (i + 1); j < sievebound; j += 2 * i + 1) {
				sieve[j] = 0;
			}
		}
	}*/

	unsigned int num_primes;
	unsigned int* primes = prime_sieve(LIMIT, &num_primes);

	unsigned long long total = 0;
	for(int i = 0; i < num_primes; i++) {
			total += primes[i];
	}
	
	printf("%llu\n", total);

	return 0;
}
