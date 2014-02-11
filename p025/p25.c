#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <gmp.h>

int main(int argc, char* argv[]) {
	unsigned int length = 1000;
	mpz_t n;
	mpz_t n1;
	mpz_t n2;
	mpz_init_set_ui(n, 1);
	mpz_init_set_ui(n1, 1);
	mpz_init(n2);
	unsigned int term = 2;
	bool found = false;

	while(!found) {
		mpz_add(n2, n1, n); // calc next term
		mpz_set(n1, n);     // save n-1 term
		mpz_set(n, n2);     // save n term

		// mpz_sizeinbase() returns faulty sizes...
		// instead simply convert to str and count the digits
		char* str = mpz_get_str(NULL, 10, n);
		size_t curr_len = strlen(str);
		free(str);
		if(curr_len >= length) {
			found = true;
		}
		term++;
	}

	printf("%u", term);

	return 0;
}

