#include <stdio.h>

typedef unsigned long long i64;

i64 gcd(i64 a, i64 b) {
	if(b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

i64 lcm(i64 a, i64 b) {
	return (a / gcd(a, b)) * b;
}

int main(int argc, char* argv[]) {

	i64 result = 1;
	for(i64 i = 2; i <= 20; i++) {
		result = lcm(result, i);
	}

	printf("%llu", result);

	return 0;
}

