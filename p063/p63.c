#include <stdio.h>

typedef __int128 i128;

i128 powi128(i128 n, i128 p) {
	i128 result = 1;
	while(p > 0) {
		result *= n;
		p--;
	}
	return result;
}

i128 digits(i128 n) {
	i128 d = 1; // assume 1 digit always
	while(n >= 10) {
		n /= 10;
		d++;
	}
	return d;
}

int main(int argc, char* argv[]) {

	int total = 0;
	for(i128 n = 1; n < 10; n++) {
		for(i128 p = 1; p < 22; p++) {
			i128 r = powi128(n, p);
			if(digits(r) == p) {
				total++;
			}
		}
	}	

	printf("%i\n", total);

	return 0;
}

