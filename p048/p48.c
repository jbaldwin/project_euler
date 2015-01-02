#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char* argv[]) {

    mpz_t sum;
    mpz_init(sum);

    for(int i = 1; i <= 1000; i++) {
        mpz_t p;
        mpz_init(p);
        mpz_ui_pow_ui(p, i, i);
        mpz_add(sum, sum, p);
    }

    char* value = mpz_get_str(NULL, 10, sum);
    int len = strlen(value);
    char* start = value + (len - 10); // only print last 10 chars
    printf("%s", start);

    free(value);

    return 0;
}

