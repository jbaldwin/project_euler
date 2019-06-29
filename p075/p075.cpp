#include <iostream>
#include <unordered_map>
#include <cmath>

/**
 * Singular integer right triangles
 * Problem 75
 *
 * It turns out that 12 cm is the smallest length of wire that can be bent to form an
 * integer sided angle triangle in exactly one way, but there are many more examples.
 *
 *      12 cm: ( 3,  4,  5)
 *      24 cm: ( 6,  8, 10)
 *      30 cm: ( 5, 12, 13)
 *      36 cm: ( 9, 12, 15)
 *      40 cm: ( 8, 15, 17)
 *      48 cm: (12, 16, 20)
 */
int main()
{
    // key=L, value=number of integer right triangles
    std::unordered_map<uint64_t, uint64_t> counts{};

    constexpr uint64_t STOP = 1'500'000;
    constexpr uint64_t MID = STOP / 2;

    for(uint64_t a = 1; a <= MID; ++a)
    {
        uint64_t a2 = a * a;
        for(uint64_t b = a; b <= MID; ++b)
        {
            // L = a + b + c
            // c^2 = a^2 + b^2

            uint64_t c2 = a2 + b * b;
            double cd = std::sqrt(c2);
            uint64_t c = static_cast<uint64_t>(cd);

            if(cd != c)
            {
                continue;
            }

            uint64_t L = a + b + c;
            if(L < 12)
            {
                continue;
            }

            if(L > STOP)
            {
                break;
            }

            ++counts[L];
        }
    }

    size_t total{0};
    for(const auto& [c, i] : counts)
    {
        if(i == 1)
        {
            ++total;
        }
    }

    std::cout << total << std::endl;

    return 0;
}
