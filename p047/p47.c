#include <stdio.h>
#include <stdbool.h>

#include "../lib/prime.h"

int prime_factors_count(int n) {
    prime_factors_t pf = prime_factors(n);

    int u_num = 0;
    unsigned long long unique[16] = { 0 };

    for(int i = 0; i < pf.num; i++) {
        bool found = false;
        for(int j = 0; j < u_num; j++) {
            if(unique[j] == pf.factors[i]) {
                found = true;
                break;
            }
        }

        if(!found) {
            unique[u_num] = pf.factors[i];
            u_num++;
        }
    }

    free(pf.factors);

    return u_num; // only report uniques
}

int main(int argc, char* argv[]) {

    int n = 2;
    int expected_primes = 4;

again:
    for(int i = expected_primes - 1; i >= 0; i--) {
        if(prime_factors_count(n + i) != expected_primes) {
            n += i + 1;
            goto again;
        }
    }

    printf("%i", n);

    return 0;
}

