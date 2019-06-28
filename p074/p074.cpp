#include <lib/Numeric.hpp>

#include <iostream>
#include <unordered_set>

int main()
{
    size_t total{0};

    std::array<uint64_t, 10> factorials{};
    factorials[0] = 1;
    for(size_t i = 1; i < 10;  ++i)
    {
        factorials[i] = lib::factorial(i);
    }

    for(uint64_t i = 1; i < 1'000'000; ++i)
    {
        std::unordered_set<uint64_t> in_chain{};
        in_chain.insert(i);

        uint64_t current = i;

        while(true)
        {
            uint64_t factorial_sum{0};

            while (current > 0)
            {
                uint64_t remainder = current % 10;
                factorial_sum += factorials[remainder];
                current /= 10;
            }

            if (in_chain.find(factorial_sum) != in_chain.end())
            {
                if(in_chain.size() == 60)
                {
                    ++total;
                }
                break;
            }
            else
            {
                in_chain.insert(factorial_sum);
                current = factorial_sum;
            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}
