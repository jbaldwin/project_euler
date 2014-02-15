#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <gmp.h>

int main(int argc, char* argv[]) {

	int lower = 2;
	int upper = 100;

	mpz_t distinct[10000];
	int count = 0;

	for(int a = lower; a <= upper; a++) {
		for(int b = lower; b <= upper; b++) {
			mpz_t c;
			mpz_init(c);
			mpz_ui_pow_ui(c, a, b);

			bool found = false;
			for(int i = 0; i < count; i++) {
				
				if(mpz_cmp(distinct[i], c) == 0) {
					found = true;
					break;
				}
			}

			if(!found) {
				mpz_set(distinct[count], c);
				count++;
			}
		}
	}

	printf("%i", count);

	return 0;
}

