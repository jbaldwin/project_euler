#include <stdio.h>

typedef unsigned long long i64;

i64 num_divisors(i64 n) {
	if(n % 2 == 0) n /= 2;
	i64 divisors = 1;
	i64 count = 0;
	while(n % 2 == 0) {
		count++;
		n /= 2;
	}

	divisors *= count + 1;
	i64 p = 3;
	while(n != 1) {
		count = 0;
		while(n % p == 0) {
			count++;
			n /= p;
		}
		divisors *= count + 1;
		p += 2;
	}
	return divisors;
}

i64 find(i64 limit) {
	i64 n = 1;
	i64 lower = num_divisors(n);
	i64 upper = num_divisors(n + 1);
	while(lower * upper < limit) {
		n++;
		lower = upper;
		upper = num_divisors(n + 1);
	}
	return n;
}

int main(int argc, char* argv[]) {

	i64 index = find(500);
	i64 triangle = (index * (index + 1)) / 2;

	printf("%llu", triangle);

	return 0;
}

