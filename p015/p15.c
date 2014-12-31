#include <stdio.h>

#include "../lib/int128.h"

typedef unsigned __int128 uint128;

uint128 factorial(uint128 n, uint128 start) {
	uint128 f = 1;
	for(uint128 i = start; i <= n; i++) f *= i;
	return f;
}

int main(int argc, char* arv[]) {
	uint128 n = 40;
	uint128 k = 20;

	uint128 total = factorial(n, k + 1) / factorial(k, 2);
	uint128_print(total);

	return 0;
}

