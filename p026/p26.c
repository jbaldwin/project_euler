#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <gmp.h>

#include "../lib/prime.h"

int main(int argc, char* argv[]) {

	int maxlen = 0;
	int maxn = -1;

	for(int n = 2; n <= 1000; n++) {
		// only need to check primes
		if(!is_prime(n)) continue;

		int rest = 1;
		for(int i = 0; i < n; i++) {
			rest = (rest * 10) % n;
		}

		int r0 = rest;
		int len = 0;
		
		do {
			rest = (rest * 10) % n;
			len++;
		} while(rest != r0);

		if(len > maxlen) {
			maxn = n;
			maxlen = len;
		}
	}

	printf("%d", maxn);

	return 0;
}

