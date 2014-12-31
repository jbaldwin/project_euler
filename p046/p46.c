#include <stdio.h>
#include <stdbool.h>

#include "../lib/prime.h"

int main(int argc, char* argv[]) {

    int limit = 10000;
    sieve_t sieve = prime_sieve(limit);

    for(int c = 3; c < limit; c += 2) {
        // ignore all primes, only want odd composites
        if(is_prime(c)) continue;

        bool found = false;

        for(int j = 0; j < sieve.num; j++) {
            int p = sieve.primes[j];

            int s = floor(sqrt((c - p ) / 2));
            if(p + 2 * s * s == c) {
                found = true;
                break;
            }
        }

        if(!found) {
            printf("%i", c);
            break;
        }
    }


    return 0;
}

