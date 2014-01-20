#include <stdio.h>
#include <stdlib.h>

#include "../lib/prime.h"

int compare(const void* v1, const void* v2) {
	unsigned long long n1 = *(unsigned long long*)v1;
	unsigned long long n2 = *(unsigned long long*)v2;

	if(n1 > n2) return 1;
	if(n1 == n2) return 0;
	return -1;
}

int main(int argc, char* argv[]) {

	int num;
	unsigned long long magic = 600851475143;
	unsigned long long* factors = prime_factors(magic, &num);
	qsort(factors, num, sizeof(unsigned long long), compare);

	printf("%llu\n", factors[num - 1]);

	return 0;
}

