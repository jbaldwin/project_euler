#include <stdio.h>
#include <gmp.h>


int main(int argc, char* argv[]) {

    int max_sum = 0;

    for(int a = 90; a < 100; a++) {
    for(int b = 90; b < 100; b++) {
        mpz_t c;
        mpz_init(c);

        mpz_ui_pow_ui(c, a, b);

        int sum = 0;
        char digits[1024] = { 0 };
        mpz_get_str(digits, 10, c);

        for(char* p = digits; *p != '\0'; p++) {
            sum += (*p) - 48;
        }

        if(sum > max_sum) {
            max_sum = sum;
        }
    }
    }

    printf("%i", max_sum);

    return 0;
}

