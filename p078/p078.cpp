#include <iostream>
#include <unordered_map>

// p(0) = 1 for a starting  point.
std::unordered_map<int64_t, int64_t> cache{{0, 1}};

auto p(int64_t n) -> int64_t
{
    auto found = cache.find(n);
    if(found != cache.end())
    {
        return found->second;
    }

    int64_t i = 0;
    int64_t k = 1;
    auto& pn = cache[n];
    pn = 0;

    while(k <= n)
    {
        int64_t sign = (i % 4 > 1) ? -1 : 1;
        pn += sign * cache[n - k];
        // Avoid using gmp big ints by capping at 1 million.
        pn %= 1'000'000;
        ++i;

        int64_t j = (i % 2 == 0) ? (i / 2 + 1) : -(i / 2 + 1);
        k = j * (3 * j - 1) / 2;
    }

    return pn;
}

/**
 * Coin partitions
 * Problem 78
 *
 * Let p(n) represent the number of different ways in which n coins can be
 * separated into piles.  For example, five coins can be separated into piles
 * in exactly seven different ways, so p(5) = 7.
 *
 *      ooooo
 *      oooo o
 *      ooo oo
 *      ooo o o
 *      oo oo o
 *      oo o o o
 *      o o o o o
 *
 *  Find the least value of n for which p(n) is divisible by one million.
 */
int main()
{
    // I can't say I really understand the algorithm behind this
    // but wikipedia has a great page on generating partitions
    // https://en.wikipedia.org/wiki/Partition_%28number_theory%29

    int64_t n = 1;
    while(true)
    {
        auto pn = p(n);

        if(pn == 0)
        {
            break;
        }

        ++n;
    }

    std::cout << n << "\n";

    return 0;
}
