#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../lib/permutations.h"

void permutation(char* p, void* data) {
    unsigned long long* sum = (unsigned long long*)data;

    // ignore all permutations starting with zero
    if(p[0] != '0') {
        static int divs[] = { 2, 3, 5, 7, 11, 13, 17 };

        // do the work now inline so a list of permutations does not need
        // to be saved and then iterated over later
        bool is_divisible = true;
        for(int j = 1; j <= 7; j++) {
            char temp[4] = { 0 };
            memcpy(temp, &p[j], 3);

            unsigned int d;
            sscanf(temp, "%u", &d);
            if(d % divs[j - 1] != 0) {
               is_divisible = false;
               break;
            }
        }

        if(is_divisible) {
            unsigned long long d;
            sscanf(p, "%llu", &d);
            (*sum) += d;
        }
    }
}

int main(int argc, char* argv[]) {

    char* start = "0123456789";
    unsigned long long sum = 0;

    // iterate through all valid permutations
    permutate(start, permutation, (void*)&sum);

    printf("%llu", sum);

    return 0;
}

