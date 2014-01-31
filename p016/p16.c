#include <stdio.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char* argv[]) {

	mpz_t result;
	mpz_init(result);
	
	mpz_ui_pow_ui(result, 2, 1000);
	char* result_str = mpz_get_str(NULL, 10, result);
	size_t len = strlen(result_str);

	unsigned int sum = 0;
	for(int i = 0; i < len; i++) {
		sum += result_str[i] - 48; // '0' is char 48
	}

	printf("%u", sum);

	return 0;
}

