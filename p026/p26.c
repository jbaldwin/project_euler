#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <gmp.h>

#include "../lib/prime.h"

int main(int argc, char* argv[]) {

	int n, i, len, maxlen, maxn;
	maxlen = 0;
	for(n = 2; n <= 1000; n++) {
		if(!is_prime(n)) continue;


		int rest = 1;
		int r0;
		for(i = 0; i < n; i++) rest = (rest * 10) % n;
		r0 = rest;
		len = 0;
		do {
			rest = (rest * 10) % n;
			len++;
		} while(rest != r0);

		if(len > maxlen) {
			maxn = n;
			maxlen = len;
		}
	}

	printf("%d: %d", maxn, maxlen);

	return 0;
}

