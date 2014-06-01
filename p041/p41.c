#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../lib/prime.h"

#define LIMIT 10000000

int substr_count(char* haystack, int len, char needle) {
	int count = 0;
	for(int i = 0; i < len; i++) {
		if(haystack[i] == needle) count++;
	}
	return count;
}

int main(int argc, char* argv[]) {

	unsigned int max_pd_prime = 0;
	sieve_t sieve = prime_sieve(LIMIT);

	for(int i = 0; i < sieve.num; i++) {
		char digits[64];
		memset(digits, '\0', 64);

		int len = sprintf(digits, "%u", sieve.primes[i]);

		bool is_pan = true;
		for(int c = 1; c <= len; c++) {
			if(substr_count(digits, len, c + 48) != 1) {
				is_pan = false;
				break;
			}
		}

		// primes are always increasing so no need to check
		if(is_pan) {
			max_pd_prime = sieve.primes[i];
		}
	}

	printf("%u", max_pd_prime);

	return 0;
}

