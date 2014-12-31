#include <stdio.h>

#include "../lib/prime.h"

int main(int argc, char* argv[]) {

    int max_len = 0;
    int max = -1;

    int limit = 1000000;
    sieve_t sieve = prime_sieve(limit);

    for(int i = sieve.num - 1; i > sieve.num - 10000; i--) {
        int prime = sieve.primes[i];
        for(int j = i - 1; j >= 0; j--) {
            int sum = 0;
            int len = 0;
            for(int k = j; k >= 0; k--) {
                sum += sieve.primes[k];
                len++;
                if(sum == prime) {
                    if(len > max_len) {
                        max_len = len;
                        max = prime;
                    }
                } else if(sum > prime) {
                    break;
                }
            }
        }
    }

    printf("%i", max);

    return 0;
}

