#include <stdio.h>

int main(int argc, char* argv[]) {

	int max = 0;
	int result = 0;

	for(int i = 1; i < 1000000; i++) {
		unsigned long long n = i;
		int count = 1;
		while(n != 1) {
			n = (n % 2 == 0) ? n / 2 : n * 3 + 1;
			count++;
		}

		if(count > max) {
			max = count;
			result = i;
		}
	}

	printf("%i\n", result);

	return 0;
}
