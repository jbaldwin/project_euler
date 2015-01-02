#include <stdio.h>
#include <string.h>

#include "../lib/prime.h"

int main(int argc, char* argv[]) {

    int limit = 1000000;
    sieve_t sieve = prime_sieve(limit);

    for(int i = 0; i < sieve.num; i++) {

        char sorig[12] = { '\0' };
        sprintf(sorig, "%i", sieve.primes[i]);
        int len = strlen(sorig);
        if(len < 4) continue;

        int primes[10] = { 0 };

        for(int c1 = 0; c1 < len; c1++) {
        for(int c2 = 1; c2 < len; c2++) {
        for(int c3 = 2; c3 < len; c3++) {
            if(c1 == c2 || c1 == c3 || c2 == c3) continue;

            char s[12] = { '\0' };
            memcpy(s, sorig, len);
            int count = 0;

            for(int r = '0'; r <= '9'; r++) {
                if(c1 == 0 && r == '0') continue;
                s[c1] = s[c2] = s[c3] = r;

                int prime_candidate = 0;
                sscanf(s, "%i", &prime_candidate);
                if(is_prime(prime_candidate)) {
                    count++;
                    primes[r - '0'] = prime_candidate;
                }
            }

            if(count == 8) {
                for(int j = 0; j < 10; j++) {
                    if(primes[j] == 0) continue;
                    // print the first and lowest prime!
                    printf("%i", primes[j]);
                    goto done; // too many loops, just quit
                }


            }
        }
        }
        }

    }

done:
    return 0;
}

