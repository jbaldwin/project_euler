#include <stdio.h>

#include "../lib/prime.h"

int main(int argc, char* argv[]) {

	int stop = 10001;
	int count = 1;
	int prime = 1;

	do {
		prime += 2;
		if(is_prime(prime)) count++;
	} while(count < stop);

	printf("%i\n", prime);

	return 0;
}
