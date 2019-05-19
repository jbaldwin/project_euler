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
            phi_n = n - 1;
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

        auto s1 = std::to_string(n);
        auto s2 = std::to_string(static_cast<uint64_t>(phi_n));

        // Can't be permutations if they differ in length.
        if(s1.length() != s2.length())
        {
            continue;
        }

        // Check if they are permutations of each other if their
        // characters can be sorted in the same manner.
        std::multiset<char> s1_set;
        std::multiset<char> s2_set;

        for(auto c : s1)
        {
            s1_set.insert(c);
        }
        for(auto c : s2)
        {
            s2_set.insert(c);
        }

        // Are these permutations of each other?
        if(s1_set == s2_set)
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
