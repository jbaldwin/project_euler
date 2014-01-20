#include <stdio.h>

typedef unsigned long long ull;

int main(int argc, char* argv[]) {

	ull square_of_sum = 0;
	ull sum_of_square = 0;

	for(ull i = 1; i <= 100; i++) {
		square_of_sum += i;
		sum_of_square += (i * i);
	}

	square_of_sum *= square_of_sum;

	printf("%llu\n", square_of_sum - sum_of_square);

	return 0;
}
