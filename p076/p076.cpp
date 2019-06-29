#include <iostream>
#include <vector>

auto sum(uint64_t n) -> uint64_t
{
    std::vector<uint64_t> table;
    table.resize(n + 1, 0);
    table[0] = 1;

    for(size_t i = 1; i < n; ++i)
    {
        for(size_t j = i; j <= n; ++j)
        {
            table[j] += table[j - i];
        }
    }

    return table[n];
}

/**
 * Counting summations
 * Problem 76
 *
 * It is possible to write five as a sum in exactly six different ways:
 *  4 + 1
 *  3 + 2
 *  3 + 1 + 1
 *  2 + 2 + 1
 *  2 + 1 + 1 + 1
 *  1 + 1 + 1 + 1 + 1
 *
 * How many different ways can one hundred be written as a sum of at least
 * two positive integers?
 */
int main()
{
    std::cout << sum(100) << "\n";
    return 0;
}
