#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "../lib/prime.h"

int main(int argc, char* argv[]) {

	int max_n = 0;
	int max_a = 0;
	int max_b = 0;

	for(int a = -999; a < 1000; a++) {
		for(int b = 2; b < 1000; b++) {
			int n = 0;
			while(true) {
				int c = (n * n) + (a * n) + b;
				if(!is_prime(c)) {
					 break;
				}
				n++;
			}

			if(n > max_n) {
				max_n = n;
				max_a = a;
				max_b = b;
			}
		}
	}

	//printf("n=%i product=%i a=%i b=%i\n", max_n, max_a * max_b, max_a, max_b);
	printf("%i", max_a * max_b);

	return 0;
}
