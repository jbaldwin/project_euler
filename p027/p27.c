#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n) {
	if(n <= 1) return false;
	if(n < 4) return true;
	if(n % 2 == 0) return false;
	if(n < 9) return true;
	if(n % 3 == 0) return false;

	int r = floor(sqrt(n));
	int f = 5;
	while(f <= r) {
		if(n % f == 0) return false;
		if(n % (f + 2) == 0) return false;
		f += 6;
	}
	return true;
}

int main(int argc, char* argv[]) {

	int max_n = 0;
	int max_a = 0;
	int max_b = 0;

	for(int a = -999; a < 1000; a++) {
		for(int b = 2; b < 1000; b++) {
			int n = 0;
			while(true) {
				int c = (n * n) + (a * n) + b;
			//	printf("c=%i", c);
				if(!is_prime(c)) {
					 break;
				}
				n++;
			}
		//	printf(" a=%i b=%i\n", a, b);

			if(n > max_n) {
				max_n = n;
				max_a = a;
				max_b = b;
			}
		}
	}

	printf("n=%i product=%i a=%i b=%i\n", max_n, max_a * max_b, max_a, max_b);

	return 0;
}
