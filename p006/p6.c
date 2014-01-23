#include <stdio.h>

typedef unsigned long long i64;

int main(int argc, char* argv[]) {

	i64 square_of_sum = 0;
	i64 sum_of_square = 0;

	for(i64 i = 1; i <= 100; i++) {
		square_of_sum += i;
		sum_of_square += (i * i);
	}

	square_of_sum *= square_of_sum;

	printf("%llu", square_of_sum - sum_of_square);

	return 0;
}

