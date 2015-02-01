#include <stdio.h>

#include "../lib/prime.h"

int main(int argc, char* argv[]) {

    int prime_count = 0;
    int total_count = 1;

    int n = 1;
    int step = 2;
    int side_len = 1;

    double percent = 0.0;

    do {
        for(int i = 0; i < 4; i++) {
            n += step;
            if(is_prime(n)) prime_count++;
        }

        total_count += 4;
        step += 2;
        side_len += 2;

        percent = (double)prime_count / (double)total_count;
    } while(percent >= 0.1);

    printf("%i", side_len);

    return 0;
}

