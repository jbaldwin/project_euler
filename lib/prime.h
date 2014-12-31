#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

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

typedef struct sieve_t {
	unsigned int  num;
	unsigned int* primes;
} sieve_t;

sieve_t prime_sieve(int limit) {
	unsigned int sievebound = (limit - 1) / 2;
	char sieve[sievebound];
	unsigned int crosslimit = floor(sqrt(sievebound));
	for(unsigned int i = 1; i < sievebound; i++) {
		sieve[i] = 1;
	}

	for(unsigned int i = 1; i < crosslimit; i++) {
		if(sieve[i]) {
			for(unsigned int j = 2 * i * (i + 1); j < sievebound; j += 2 * i + 1) {
				sieve[j] = 0;
			}
		}
	}

	unsigned int num = 1;
	for(unsigned int i = 1; i < sievebound; i++) {
		if(sieve[i]) num++;
	}

	unsigned int* primes = malloc(sizeof(unsigned int) * num);
	primes[0] = 2;
	int p = 1;
	for(int i = 1; i < sievebound; i++) {
		if(sieve[i]) {
			primes[p] = 2 * i + 1;
			p++;
		}
	}

	sieve_t result;
	result.num = num;
	result.primes = primes;

	return result;
}

typedef struct prime_factors_t {
	unsigned long long  num;
	unsigned long long* factors;
} prime_factors_t;

prime_factors_t prime_factors(unsigned long long n) {
	int num = 0;
	int size = 8;
	unsigned long long* factors = malloc(sizeof(unsigned long long) * size);

	unsigned long long d = 2;
	while(n > 1) {
		while(n % d == 0) {
			if(num == size) {
				size += 8;
				factors = realloc(factors, sizeof(unsigned long long) * size);
			}

			factors[num] = d;
			n /= d;
			num++;
		}
		d += 1;
		if(d * d > n) {
			if(n > 1) {
				if(num == size) {
					size += 8;
					factors = realloc(factors, sizeof(unsigned long long) * size);
				}
				factors[num] = n;
				num++;
			}
			break;
		}
	}

	// reduce memory footprint
	prime_factors_t result;
	result.factors = realloc(factors, sizeof(unsigned long long) * num);
	result.num = num;
	return result;
}

