#include <lib/Prime.hpp>
#include <lib/Permutations.hpp>

#include <iostream>
#include <set>
#include <string>
#include <limits>

/**
 * Totient permutation
 * Problem 70
 *
 * Euler's Totient function, phi(n) [sometimes called the phi function], is used to determine
 * the number of positive numbers less than or equal to n which are relatively prime to n.
 * For example, as 1,2,4,5,7, and 8, are all less tha nine and relatively prime to nine,
 * phi(9) = 6.
 *
 * The number 1 is considered to be relatively prime to every positive number, so phi(1) = 1.
 *
 * Interestingly, phi(87109)=79180, and it can be seen that 87109 is a permutation of 79180.
 *
 * Find the value of n, 1 < n < 10^7, for which phi(n) is a permutation of n and the ratio
 * of n/phi(n) produces a minimum.
 */
int main()
{
    size_t result_n{1};
    double result_n_div_phi_n{std::numeric_limits<double>::max()};

    for(size_t n = 2; n < 10'000'000; ++n)
    {
        double n_div_phi_n{0.0};
        double phi_n = 0;

        if(lib::is_prime(n))
        {
            /**
             * By nature n - 1 cannot be a permutation, skip all primes.
             */
            // phi_n = n - 1;
            continue;
        }
        else
        {
            auto pfactors = lib::prime_factors(n);

            phi_n = n;
            for(auto pf : pfactors)
            {
                phi_n *= (1 - (((double)1)/ pf));
            }
        }

        // Are these permutations of each other?
        if(lib::is_permutation(n, static_cast<uint64_t>(phi_n)))
        {
            n_div_phi_n = ((double)n) / phi_n;

            if(n_div_phi_n < result_n_div_phi_n)
            {
                result_n_div_phi_n = n_div_phi_n;
                result_n = n;
            }
        }
    }

    std::cout << result_n;

    return 0;
}
