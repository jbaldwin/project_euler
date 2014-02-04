#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <stdbool.h>

#define MAX_PROPER_DIVISORS 128

typedef struct proper_divisors_t {
    int* divisors;
    int len;
} proper_divisors_t;

proper_divisors_t proper_divisors(int n) {
    proper_divisors_t pd;
	pd.divisors = malloc(sizeof(int) * MAX_PROPER_DIVISORS);
	pd.divisors[0] = 1;
    pd.len = 1;

    int s = floor(sqrt(n));

    for(int i = 2; i <= s; i++) {
        if(n % i == 0) {
            int factor = n / i;
			pd.divisors[pd.len]     = i;
			pd.divisors[pd.len + 1] = factor;
			pd.len += 2;
        }
    }

	return pd;
}

int proper_divisors_sum(proper_divisors_t pd) {
	int total = 0;
	for(int i = 0; i < pd.len; i++) {
		total += pd.divisors[i];
	}
	return total;
}

typedef struct amicable_pair_t {
	int a;
	int b;
} amicable_pair_t;

typedef struct amicable_pairs_t {
	amicable_pair_t* pairs;
	int count;
	int capacity;
} amicable_pairs_t;

amicable_pairs_t amicable_pairs_init() {
	amicable_pairs_t ap;
	ap.pairs = malloc(sizeof(amicable_pair_t) * 8);
	ap.count = 0;
	ap.capacity = 8;
	return ap;
}

void amicable_pairs_add(amicable_pairs_t* ap, int a, int b) {
	if(ap->count == ap->capacity) {
		ap->capacity += 8;
		ap->pairs = realloc(ap->pairs, sizeof(amicable_pair_t) * ap->capacity);
	}
	ap->pairs[ap->count].a = a;
	ap->pairs[ap->count].b = b;
	ap->count++;
}

bool is_amicable_pair_part(amicable_pairs_t ap, int n) {
	for(int i = 0; i < ap.count; i++) {
		if(ap.pairs[i].a == n || ap.pairs[i].b == n) return true;
	}
	return false;
}

int main(int argc, char* argv[]) {
	amicable_pairs_t ap = amicable_pairs_init();

    for(int a = 1; a < 10000; a++) {
		// make sure it isn't a duplicate
		// since all pairs will show up twice
		if(is_amicable_pair_part(ap, a)) continue;

        int b = proper_divisors_sum(proper_divisors(a));
		if(a == b) continue;

		if(a == proper_divisors_sum(proper_divisors(b))) {
			amicable_pairs_add(&ap, a, b);
		}
    }

	int amicable_sum = 0;
	for(int i = 0; i < ap.count; i++) {
		amicable_sum += ap.pairs[i].a;
		amicable_sum += ap.pairs[i].b;
	}
	printf("%i", amicable_sum);

    return 0;
}

