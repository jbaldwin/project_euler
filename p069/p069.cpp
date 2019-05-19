#include <lib/Prime.hpp>
#include <lib/Numeric.hpp>

#include <iostream>

/**
 * Totient maximum
 * Problem 69
 * 
 * Euler's Totient function, phi(n) [sometimes called the phi function], is used to determine the
 * number of numbers less than n which are relatively prime to n.  For example, as 1,2,4,5,6, and 8,
 * are all less than nine and relatively prime to nine, phi(9) = 6.
 *
 *  n   Relatively Prime    phi(n)  n/phi(n)
 *  2   1                   1       2
 *  3   1,2                 2       1.5
 *  4   1,3                 2       2
 *  5   1,2,3,4             4       1.25
 *  6   1,5                 2       3
 *  7   1,2,3,4,5,6         6       1.1666...
 *  8   1,3,5,7             4       2
 *  9   1,2,4,5,7,8         6       1.5
 *  10  1,3,7,9             4       2.5
 *
 * It can be seen that n=6 produces a maximum of n/phi(n) for n <= 10.
 *
 * Find the value of n <= 1,000,000 for which n/phi(n) is a maximum.
 */
int main()
{
    size_t max_n{0};
    double max_n_div_phi_n{0.0};

    for(size_t n = 2; n <= 1'000'000; ++n)
    {
        double n_div_phi_n{0.0};
        double phi_n{1.0};

        if(lib::is_prime(n))
        {
            /**
             * When the number is prime the phi(n) = n - 1.
             */
            phi_n = n - 1;
        }
        else
        {
            /**
             * When the number is composite the phi(n) = n * (1 - (1/pf1)) * (1 - (1/pf2)) * (1 - (1/pfN))
             */
            auto pfactors = lib::prime_factors(n);

            phi_n = n;
            for(auto pf : pfactors)
            {
                phi_n *= (1 - (((double)1) / pf));
            }
        }

        n_div_phi_n = ((double)n) / phi_n;

        if(n_div_phi_n > max_n_div_phi_n)
        {
            max_n_div_phi_n = n_div_phi_n;
            max_n = n;
        }
    }

    std::cout << max_n;

    return 0;
}
