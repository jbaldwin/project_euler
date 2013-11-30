#include <stdio.h>
#include <math.h>
#include <memory.h>

#define LIMIT 28123

int sum_of_proper_divisors(int n) {
	int r =  floor(sqrt(n));
	int sum = 1;

	if(r * r == n) {
		sum += r;
		r -= 1;
	}

	int step = 1;
	int i = 2;
	if(n % 2 == 1) {
		step = 2;
		i = 3;
	}

	while(i <= r) {
		if(n % i == 0) {
			sum += i + (n / i);
		}
		i += step;
	}

	return sum;
}

int main(int argc, char* argv[]) {
	// initialize abundant numbers to false
	int abundants[LIMIT];
	memset(abundants, 0, sizeof(int) * LIMIT); 

	// find all abundant numbers up to the limit
	for(int i = 12; i <= LIMIT; i++) {
		int sum = sum_of_proper_divisors(i);
		if(i < sum && sum <= LIMIT) {
			abundants[i] = 1;
		}
	}

	// find the last abundant number to optimize the next section
	int last_abundant = LIMIT;
	for(int i = LIMIT - 1; i >= 0; i--) {
		if(abundants[i] == 1) {
			last_abundant = i;
			break;
		}
	}

	// add up all numbers that are not a sum of two abundant numbers
	// this is done by checking each number from 1 to LIMIT to
	// see if its sum compliment exists as an abundant
	int sum = 0;
	for(int i = 1; i < LIMIT; i++) {
		for(int e = 0; e < last_abundant; e++) {
			if(abundants[e] == 1) {
				int compliment = i - e;
				if(compliment == 0) goto found;
				if(compliment < 0) continue;
				if(abundants[compliment] == 1) {
					goto not_found;
				}
			}
		}
		found:
		sum += i;
		not_found: ;
	}

	printf("%i\n", sum);
}
