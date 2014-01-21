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

	unsigned long long magic = 600851475143;
	prime_factors_t pf = prime_factors(magic);
	qsort(pf.factors, pf.num, sizeof(unsigned long long), compare);

	printf("%llu\n", pf.factors[pf.num - 1]);

	return 0;
}

