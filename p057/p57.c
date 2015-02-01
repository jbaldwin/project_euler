#include <stdio.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char* argv[]) {

    int count = 0;

    mpz_t n;
    mpz_t d;
    mpz_t n1;
    mpz_t d1;

    mpz_init_set_ui(n, 1);
    mpz_init_set_ui(d, 1);
    mpz_init_set_ui(n1, 3);
    mpz_init_set_ui(d1, 2);

    for(int i = 2; i <= 1000; i++) {
        mpz_t n2;
        mpz_t d2;

        mpz_init(n2);
        mpz_init(d2);

        mpz_mul_ui(n2, n1, 2);
        mpz_add(n2, n2, n);

        mpz_mul_ui(d2, d1, 2);
        mpz_add(d2, d2, d);

        char n_digits[1024] = { '\0' };
        char d_digits[1024] = { '\0' };

        mpz_get_str(n_digits, 10, n2);
        mpz_get_str(d_digits, 10, d2);

        int nlen = strlen(n_digits);
        int dlen = strlen(d_digits);

        //mpz_out_str(stdout, 10, n2);
        //printf("\t");
        //mpz_out_str(stdout, 10, d2);
        //getc(stdin);

        if(nlen > dlen) {
            count++;
        }

        mpz_set(n, n1);
        mpz_set(n1, n2);

        mpz_set(d, d1);
        mpz_set(d1, d2);
    }

    printf("%i", count);

    return 0;
}

