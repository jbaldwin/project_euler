#include <stdio.h>
#include <memory.h>
#include <stdbool.h>

#include "../lib/prime.h"

void rotate(char* digits, int len) {
	char first = digits[0];
	memmove(&digits[0], &digits[1], len - 1);
	digits[len - 1] = first;
}

bool is_circular_prime(int prime) {
	if(!is_prime(prime)) return false;

	if(prime < 10) return true;

	char digits[64];
	int len = sprintf(digits, "%i", prime);
	rotate(digits, len);

	for(int i = 1; i < len; i++) {
		int n;
		sscanf(digits, "%i", &n);
		if(!is_prime(n)) {
			return false;
		}

		rotate(digits, len);
	}

	return true;
}

bool contains_even_digits(int n) {
	while(n > 0) {
		if(n % 2 == 0) return true;
		n /= 10;
	}
	return false;
}

int main(int argc, char* argv[]) {

	int count = 1;	// count '2' implicitly

	for(int i = 3; i < 1000000; i += 2) {
		if(!contains_even_digits(i) && is_circular_prime(i)) {
			count++;
		}
	}

	printf("%i", count);

	return 0;
}

