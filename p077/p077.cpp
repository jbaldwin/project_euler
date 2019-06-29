#include <lib/Prime.hpp>
#include <lib/Permutations.hpp>

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <list>

auto reverse(std::vector<uint64_t> i) -> std::list<uint64_t>
{
    std::list<uint64_t> reversed{};

    for(auto x = i.rbegin(); x != i.rend(); ++x)
    {
        reversed.push_back(*x);
    }

    return reversed;
}

/**
 * This function will recursively call itself 'primes.size()' times to test all valid paths.
 *
 * @param primes        The remaining primes to try.
 * @param current_set   The current set of primes that are 'summed'.  This is only useful for debugging.
 * @param current_sum   The current sum of primes in 'current_set'.
 * @param n             The 'n' value this function is trying to sum to.
 * @return
 */
auto sum(
    std::list<uint64_t> primes,
    std::list<uint64_t> current_set,
    uint64_t current_sum,
    uint64_t n
) -> uint64_t
{
    uint64_t count{0};

    current_sum += primes.front();
    current_set.push_back(primes.front());

    if(current_sum == n)
    {
        return 1;
    }

    if(current_sum > n)
    {
        return 0;
    }

    // For every prime remaining (including the current prime!) call recursively.
    while(!primes.empty())
    {
        count += sum(primes, current_set, current_sum, n);
        primes.erase(primes.begin());
    }

    return count;
}

/**
 * Prime summations
 * Problem 77
 *
 * It is possible to write ten as the sum of primes in exactly five different ways:
 *      7 + 3
 *      5 + 5
 *      5 + 3 + 2
 *      3 + 3 + 2 + 2
 *      2 + 2 + 2 + 2
 *
 * What is the first value which can be written as the sum of primes in over five thousand ways?
 */
int main()
{
    uint64_t n = 10;
    while(true)
    {
        std::vector<uint64_t> primes{};
        for(uint64_t p = 2; p < n; ++p)
        {
            if(lib::is_prime(p))
            {
                primes.push_back(p);
            }
        }

        std::list<uint64_t> reversed = reverse(primes);

        uint64_t count{0};
        while(!reversed.empty())
        {
            count += sum(reversed, {}, 0, n);
            reversed.pop_front();
        }

        if(count > 5000)
        {
            std::cout << n << "\n";
            break;
        }

        ++n;
    }

    return 0;
}
