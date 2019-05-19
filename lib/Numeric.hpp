#pragma once

#include <set>
#include <cstdint>

namespace lib
{

/**
 * Generates the unique set of factors for N.
 * @param n The number to calculate its factors.
 * @return The unique set of Factors for N.
 */
auto factors(uint64_t n) -> std::set<uint64_t>
{
    std::set<uint64_t> factors{1, n};

    uint64_t d = 2;
    while(d * d <= n)
    {
        if(n % d == 0)
        {
            uint64_t d1 = n / d;
            factors.insert(d);
            factors.insert(d1);
        }

        ++d;
    }

    return factors;
}

} // namespace lib

