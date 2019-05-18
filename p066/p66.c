#include <stdio.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char* argv[])
{
    int result = 0;
    mpz_t pmax;

    mpz_init_set_ui(pmax, 0);

    mpz_t mul1, mul2, mul3, sub1, add1;
    mpz_init_set_ui(mul1, 0);
    mpz_init_set_ui(mul2, 0);
    mpz_init_set_ui(mul3, 0);
    mpz_init_set_ui(sub1, 0);
    mpz_init_set_ui(add1, 0);

    mpz_t mpz_D;
    mpz_init(mpz_D);

    mpz_t one;
    mpz_init_set_ui(one, 1);

    for(int D = 2; D <= 1000; D++)
    {
        mpz_set_ui(mpz_D, D);

        if(mpz_perfect_square_p(mpz_D))
        {
            continue;
        }

        mpz_t limit;
        mpz_init(limit);
        mpz_sqrt(limit, mpz_D);

        mpz_t m;
        mpz_t d;
        mpz_t a;

        mpz_init_set_ui(m, 0);
        mpz_init_set_ui(d, 1);
        mpz_init_set(a, limit);

        mpz_t num;
        mpz_t numm1;
        mpz_t numm2;

        mpz_init_set(num, a);
        mpz_init_set_ui(numm1, 1);
        mpz_init(numm2);

        mpz_t den;
        mpz_t denm1;
        mpz_t denm2;

        mpz_init_set_ui(den, 1);
        mpz_init_set_ui(denm1, 0);
        mpz_init(denm2);

        while(1)
        {
            mpz_mul(mul1, num, num);
            mpz_mul(mul2, den, den);
            mpz_mul_ui(mul3, mul2, D);
            mpz_sub(sub1, mul1, mul3);

            if(!mpz_cmp(sub1, one))
            {
                break;
            }

            mpz_mul(mul1, d, a);
            mpz_sub(m, mul1, m);

            mpz_mul(mul1, m, m);
            mpz_ui_sub(sub1, D, mul1);
            mpz_div(d, sub1, d);

            mpz_add(add1, limit, m);
            mpz_div(a, add1, d);

            mpz_set(numm2, numm1);
            mpz_set(numm1, num);
            mpz_set(denm2, denm1);
            mpz_set(denm1, den);

            mpz_mul(mul1, a, numm1);
            mpz_add(num, mul1, numm2);

            mpz_mul(mul1, a, denm1);
            mpz_add(den, mul1, denm2);
        }

        if(mpz_cmp(num, pmax) > 0)
        {
            mpz_set(pmax, num);
            result = D;
        }
    }


    printf("%i", result);

    return 0;
}
