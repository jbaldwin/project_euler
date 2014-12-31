#include <stdio.h>
#include <stdbool.h>

#include "../lib/prime.h"
#include "../lib/permutations.h"

typedef struct found_t {
    int len;
    int values[16];
} found_t;

void permutation(char* p, void* data) {
    int prime = 0;
    sscanf(p, "%i", &prime);

    found_t* found = (found_t*)data;

    if(p[0] != '0' && is_prime(prime)) {
        bool exists = false;
        for(int i = 0; i < found->len; i++) {
            if(prime == found->values[i]) {
                exists = true;
                break;
            }
        }

        if(!exists) {
            found->values[found->len] = prime;
            found->len++;
        }
    }
}

int main(int argc, char* argv[]) {

    sieve_t sieve = prime_sieve(4000);
    int magic = 3330;

    int problem_defined = 1487; // ignore the problem's given answer
    int answer = -1;

    for(int i = 0; i < sieve.num; i++) {
        unsigned int prime = sieve.primes[i];

        // we can constrain the search space a bit
        if(prime < 1000) continue;
        if(prime > 4000) break;

        char str[10] = { '\0' };
        sprintf(str, "%i", prime);

        found_t found;
        memset(&found, '\0', sizeof(found_t));
        permutate(str, permutation, &found);

        for(int j = 0; j < found.len; j++) {
            int chk1 = found.values[j] + magic;
            int chk2 = chk1 + magic;

            bool chk1_exists = false;
            bool chk2_exists = false;
            for(int z = 0; z < found.len; z++) {
                if(chk1 == found.values[z]) chk1_exists = true;
                if(chk2 == found.values[z]) chk2_exists = true;
            }

            if(chk1_exists && chk2_exists && problem_defined != found.values[j]) {
                answer = found.values[j];
                // break both for loops
                i = sieve.num;
                break;
            }
        }
    }

    printf("%i%i%i", answer, answer + magic, answer + magic + magic);
    return 0;
}

