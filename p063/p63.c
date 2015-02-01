#include <stdio.h>

#include "../lib/int128.h"

typedef __int128 i128;

int digits(i128 n) {
	int d = 1; // assume 1 digit always
	while(n >= 10) {
		n /= 10;
		d++;
	}
	return d;
}

int main(int argc, char* argv[]) {

	int total = 0;
	for(int n = 1; n < 10; n++) {
		for(int p = 1; p < 22; p++) {
			i128 r = int128_power(n, p);
			if(digits(r) == p) {
				total++;
			}
		}
    }

	printf("%i", total);

	return 0;
}

