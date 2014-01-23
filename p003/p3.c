#include <stdio.h>
#include <stdlib.h>

#include "../lib/prime.h"

typedef unsigned long long i64;

int compare(const void* v1, const void* v2) {
	i64 n1 = *(i64*)v1;
	i64 n2 = *(i64*)v2;

	if(n1 > n2) return 1;
	if(n1 == n2) return 0;
	return -1;
}

int main(int argc, char* argv[]) {

	i64 magic = 600851475143;
	prime_factors_t pf = prime_factors(magic);
	qsort(pf.factors, pf.num, sizeof(i64), compare);

	printf("%llu", pf.factors[pf.num - 1]);

	return 0;
}

