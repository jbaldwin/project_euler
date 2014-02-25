#include <stdio.h>

unsigned int factorial(unsigned int n) {
	unsigned int sum = 1;
	for(unsigned int i = n; i > 1; i--) {
		sum *= i;
	}
	return sum;
}

int main(int argc, char* argv[]) {

	unsigned int sum = 0;

	for(unsigned int i = 3; i < 99999; i++) {
		unsigned int fact_sum = 0;
		unsigned int j = i;
		while(j > 0) {
			fact_sum += factorial(j % 10);
			j /= 10;
		}
		if(i == fact_sum) {
			sum += i;
		}
	}

	printf("%u", sum);

	return 0;
}

