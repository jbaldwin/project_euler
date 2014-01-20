#include <stdio.h>

int main(int argc, char* argv[]) {

	for(int a = 1; a < 998; a++) {
		for(int b = 1; b < 998; b++) {
			int c = 1000 - a - b;
			if(c <= 0) continue;

			if(a * a + b * b == c * c) {
				printf("%i\n", a * b * c);
				goto found;
			}
		}
	}
found:
	return 0;
}

