#include <stdio.h>

typedef unsigned long long i64;

int main(int argc, char* argv[]) {

	i64 total = 0;
	i64 last = 1;
	i64 curr = 2;
	i64 next = 0;
	while(next <= 4000000) {
		if(curr % 2 == 0) {
			total += curr;
		}
		next = last + curr;
		last = curr;
		curr = next;
	}

	printf("%llu", total);

	return 0;
}

