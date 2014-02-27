#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdbool.h>

#include "../lib/prime.h"

bool left_trunc(char* s, int len) {
	char* ps = s;
	for(int i = 0; i < len; i++) {
		int n;
		sscanf(ps, "%i", &n);
		if(!is_prime(n)) {
			return false;
		}
		ps++;
	}
	return true;
}

bool right_trunc(char* s, int len) {
	for(int i = len - 1; i >= 0; i--) {
		int n;
		sscanf(s, "%i", &n);
		if(!is_prime(n)) {
			return false;
		}
		s[i] = '\0';
	}
	return true;
}

bool is_trunc_prime(char* s, int len) {
	char left_buf[64];
	char right_buf[64];
	memset(left_buf, '\0', 64);
	memset(right_buf, '\0', 64);

	strcpy(left_buf, &s[1]);
	strcpy(right_buf, s);
	right_buf[len - 1] = '\0';

	return left_trunc(left_buf, len - 1) && right_trunc(right_buf, len - 1);
}

int main(int argc, char* argv[]) {

	int sum = 0;
	int count = 0;
	int i = 11;

	while(count < 11) {
		if(is_prime(i)) {
			char prime_str[64];
			memset(prime_str, '\0', 64);
			int len = sprintf(prime_str, "%i", i);

			if(is_trunc_prime(prime_str, len)) {
				sum += i;
				count++;
			}
		}
		i += 2;
	}
	

	printf("%i", sum);

	return 0;
}

