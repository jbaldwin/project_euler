#include <stdio.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char* argv[]) {

    mpz_t n_k1;
    mpz_t n;

    mpz_init_set_ui(n_k1, 1);
    mpz_init_set_ui(n,    2);

    for(int i = 2; i <= 100; i++) {
        mpz_t n_k2;
        mpz_init_set(n_k2, n_k1);

        mpz_t a_k;
        mpz_init_set_ui(a_k, (i % 3 == 0) ? 2 * (i / 3) : 1);
        mpz_set(n_k1, n);

        mpz_mul(a_k, a_k, n_k1);
        mpz_add(a_k, a_k, n_k2);
        mpz_set(n, a_k);
    }

    char* s = mpz_get_str(NULL, 10, n);

    int len = strlen(s);
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += s[i] - 48;
    }

    printf("%i", sum);

    return 0;
}

