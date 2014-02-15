#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[]) {

	int power = 5;
	int start = 2;
	int end = pow(9, 5) * 6;

	int sum = 0;

	for(int i = start; i <= end; i++) {
		char s[128];
		int len = sprintf(s, "%i", i);

		int sum_pow = 0;
		for(int j = 0; j < len; j++) {
			sum_pow += pow(s[j] - 48, power);
		}

		if(sum_pow == i) {
			sum += i;
		}
	}

	printf("%i", sum);

	return 0;
}

