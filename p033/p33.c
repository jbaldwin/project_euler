#include <stdio.h>

#include "../lib/fractions.h"

int main(int argc, char* argv[]) {

	int numerator = 1;
	int denominator = 1;

	for(int n = 10; n <= 99; n++) {
	for(int d = 10; d <= 99; d++) {
		if(n >= d) continue;

		int n_1 = (n / 10) % 10;
		int n_2 = n % 10;

		int d_1 = (d / 10) % 10;
		int d_2 = d % 10;

		if(	n_2 == d_1 &&
			n_1 != d_2 &&
			d_2 != 0) {

			if((double)n_1 / d_2 == (double)n / d) {
				numerator *= n;
				denominator *= d;
			}
		}
	}
	}

	fraction_reduce_i32(&numerator, &denominator);

	printf("%i", denominator);

	return 0;
}

