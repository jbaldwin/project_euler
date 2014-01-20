#include <stdio.h>

typedef unsigned long long ull;

int main(int argc, char* argv[]) {

	ull total = 0;
	ull last = 1;
	ull curr = 2;
	ull next = 0;
	while(next <= 4000000) {
		if(curr % 2 == 0) {
			total += curr;
		}
		next = last + curr;
		last = curr;
		curr = next;
	}

	printf("%llu\n", total);

	return 0;
}
