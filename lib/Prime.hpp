#pragma once

#include <set>
#include <cmath>
#include <cstdint>

namespace lib
{

/**
 * Determines if a number is prime.
 * @param n The number to see if it is prime or not.
 * @return Prime or not? That is the question.
 */
bool is_prime(uint64_t n) {
    if(n <= 1) return false;
    if(n < 4) return true;
    if(n % 2 == 0) return false;
    if(n < 9) return true;
    if(n % 3 == 0) return false;

    uint64_t r = static_cast<uint64_t>(floor(sqrt(n)));
    uint64_t f = 5;
    while(f <= r) {
        if(n % f == 0) return false;
        if(n % (f + 2) == 0) return false;
        f += 6;
    }
    return true;
}

/**
 * Generates all prime factors for N.
 * @param n The number to generate prime factors for.
 * @return The unique set of prime factors for N.
 */
auto prime_factors(uint64_t n) -> std::set<uint64_t>
{
    std::set<uint64_t> factors;

    uint64_t d = 2;
    while(n > 1)
    {
        while(n % d == 0)
        {
            factors.insert(d);
            n /= d;
        }

        d += 1;

        if(d * d > n)
        {
            if(n > 1)
            {
                factors.insert(n);
            }
            break;
        }
    }

    return factors;
}

} // namespace lib
