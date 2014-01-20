#include <stdio.h>

typedef unsigned long long ull;

ull gcd(ull a, ull b) {
	if(b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

ull lcm(ull a, ull b) {
	return (a / gcd(a, b)) * b;
}

int main(int argc, char* argv[]) {

	ull result = 1;
	for(ull i = 2; i <= 20; i++) {
		result = lcm(result, i);
	}
	printf("%llu\n", result);

	return 0;
}

