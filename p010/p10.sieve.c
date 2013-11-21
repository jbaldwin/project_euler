#include <stdio.h>

#define LIMIT 2000000

int main(int argc, char* argv[]) {
	int sieve[LIMIT];

	unsigned long long total = 0;
	int i;
	for(i = 0; i < LIMIT; i++) {
		sieve[i] = i;
	}
	sieve[0] = 0; // mark 0 and 1 as non-prime
	sieve[1] = 0;

	for(i = 0; i < LIMIT; i++) {
		if(sieve[i] != 0) {
			int p = sieve[i];
			for(int j = p + p; j < LIMIT; j += p) {
				sieve[j] = 0;
			}
		}
	}

	// all non-primes are set to 0
	for(i = 0; i < LIMIT; i++) {
		total += sieve[i];
	}
	
	printf("%llu\n", total);

	return 0;
}
