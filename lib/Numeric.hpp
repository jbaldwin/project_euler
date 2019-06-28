#pragma once

#include <set>
#include <map>
#include <cstdint>

namespace lib
{

/**
 * Calculates the greatest common divisor of a and b.
 */
auto gcd(uint64_t a, uint64_t b) -> uint64_t
{
    while(b != 0)
    {
        uint64_t t = a;
        a = b;
        b = t % b;
    }
    return a;
}

/**
 * Calculates the least common multiple of a and b.
 */
auto lcm(uint64_t a, uint64_t b) -> uint64_t
{
    return (a / gcd(a, b)) * b;
}

auto fraction_reduce(uint64_t& n, uint64_t& d) -> void
{
    for(uint64_t i = n; i >= 1; --i)
    {
        if(n % i == 0 && d % i == 0) {
            n /= i;
            d /= i;
            break;
        }
    }
}

/**
 * Generates the unique set of factors for N.
 * @param n The number to calculate its factors.
 * @return The unique set of Factors for N.
 */
auto factors(uint64_t n) -> const std::set<uint64_t>&
{
    thread_local std::map<uint64_t, std::set<uint64_t>> cache{};

    auto found = cache.find(n);
    if(found != cache.end())
    {
        return found->second;
    }

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

    return cache.emplace(n, std::move(factors)).first->second;
}

auto factorial(uint64_t n) -> uint64_t
{
    thread_local std::map<uint64_t, uint64_t> results{{1, 1}};

    auto found = results.find(n);
    if(found != results.end())
    {
        return found->second;
    }

    uint64_t value{1};
    for(uint64_t i = 2; i <= n; ++i)
    {
        value *= i;
    }

    results[n] = value;

    return value;
};

} // namespace lib

