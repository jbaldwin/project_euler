#include <stdbool.h>
#include <math.h>
#include <malloc.h>

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

unsigned long long* prime_factors(unsigned long long n, int* out_num_factors) {
	int count = 0;
	int size = 8;
	unsigned long long* factors = malloc(sizeof(unsigned long long) * size);

	unsigned long long d = 2;
	while(n > 1) {
		while(n % d == 0) {
			if(count == size) {
				size += 8;
				factors = realloc(factors, sizeof(unsigned long long) * size);
				if(factors == NULL) return NULL; // out of memory uh oh!
			}

			factors[count] = d;
			n /= d;
			count++;
		}
		d += 1;
		if(d * d > n) {
			if(n > 1) {
				if(count == size) {
					size += 8;
					factors = realloc(factors, sizeof(unsigned long long) * size);
					if(factors == NULL) return NULL;
				}
				factors[count] = n;
				count++;
			}
			break;
		}
	}

	// reduce memory footprint
	factors = realloc(factors, sizeof(unsigned long long) * count);
	*out_num_factors = count;
	return factors;
}

