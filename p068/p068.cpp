#include <iostream>
#include <array>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>
#include <numeric>

#include <lib/permutations.hpp>
#include <gmpxx.h>

template<typename DataType>
auto sum(const DataType& data) -> uint64_t
{
    return std::accumulate(std::begin(data), std::end(data), 0ul);
}

auto magic3gonring(bool print_all_solutions) -> uint64_t
{
    std::unordered_map<int, std::set<std::array<std::array<int, 3>, 3>>> results;

    const std::array<int, 6> numbers{1, 2, 3, 4, 5, 6};

    // 4,3,2; 6,2,1; 5,1,3
    // 0,1,2, 3,2,4  5,4,1

    lib::permutate<int, 6>(
        numbers,
        [&results](const auto& p)
        {
            std::array<int, 3> line1{p[0], p[1], p[2]};
            std::array<int, 3> line2{p[3], p[2], p[4]};
            std::array<int, 3> line3{p[5], p[4], p[1]};

            auto line1_total = sum(line1);
            auto line2_total = sum(line2);
            auto line3_total = sum(line3);

            if(line1_total == line2_total && line1_total == line3_total)
            {
                // We've got a valid combo!
                auto& sets = results[line1_total];

                if(line1[0] < line2[0] && line1[0] < line3[0])
                {
                    sets.insert({line1, line2, line3});
                }
                else if(line2[0] < line1[0] && line2[0] < line3[0])
                {
                    sets.insert({line2, line3, line1});
                }
                else
                {
                    sets.insert({line3, line1, line2});
                }
            }
        }
    );

    if(print_all_solutions)
    {
        for(auto& [total, values] : results)
        {
            for(auto& magic3gon : values)
            {
                std::cout << "total: " << total << "\t\t";
                for(auto i : magic3gon[0]) std::cout << i << " ";
                std::cout << "; ";
                for(auto i : magic3gon[1]) std::cout << i << " ";
                std::cout << "; ";
                for(auto i : magic3gon[2]) std::cout << i << " ";
                std::cout << "\n";
            }
        }
    }

    uint64_t max{0};
    for(auto& [total, values] : results)
    {
        for(auto& magic3gon : values)
        {
            std::string concat{};
            concat.reserve(32);

            for(auto line : magic3gon)
            {
                for(auto i : line)
                {
                    concat += std::to_string(i);
                }
            }

            uint64_t value = std::stoul(concat);

            max = std::max(value,  max);
        }
    }

    return max;
}

auto magic5gonring(bool print_all_solutions) -> uint64_t
{
    std::unordered_map<int, std::set<std::array<std::array<int, 3>, 5>>> results;

    const std::array<int, 10> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 1,2,3,; 4,3,5; 6,5,7; 8,7,9; 10,9,2

    lib::permutate<int, 10>(
        numbers,
        [&results](const auto& p)
        {
            std::array<int, 3> line1{p[0], p[1], p[2]};
            std::array<int, 3> line2{p[3], p[2], p[4]};
            std::array<int, 3> line3{p[5], p[4], p[6]};
            std::array<int, 3> line4{p[7], p[6], p[8]};
            std::array<int, 3> line5{p[9], p[8], p[1]};

            auto line1_total = sum(line1);
            auto line2_total = sum(line2);
            auto line3_total = sum(line3);
            auto line4_total = sum(line4);
            auto line5_total = sum(line5);

            if(
                   line1_total == line2_total
                && line1_total == line3_total
                && line1_total == line4_total
                && line1_total == line5_total
            )
            {
                // We've got a valid combo!

                auto& sets = results[line1_total];

                if(line1[0] < line2[0] && line1[0] < line3[0] && line1[0] < line4[0] && line1[0] < line5[0])
                {
                    sets.insert({line1, line2, line3, line4, line5});
                }
                else if(line2[0] < line1[0] && line2[0] < line3[0] && line2[0] < line4[0] && line2[0] < line5[0])
                {
                    sets.insert({line2, line3, line4, line5, line1});
                }
                else if(line3[0] < line2[0] && line3[0] < line1[0] && line3[0] < line4[0] && line3[0] < line5[0])
                {
                    sets.insert({line3, line4, line5, line1, line2});
                }
                else if(line4[0] < line2[0] && line4[0] < line3[0] && line4[0] < line1[0] && line4[0] < line5[0])
                {
                    sets.insert({line4, line5, line1, line2, line3});
                }
                else
                {
                    sets.insert({line5, line1, line2, line3, line4});
                }
            }
        }
    );

    if(print_all_solutions)
    {
        for (auto&[total, values] : results)
        {
            for (auto& magic5gon : values)
            {
                std::cout << "total: " << total << "\t\t";
                for (auto line : magic5gon)
                {
                    for (auto i : line)
                    {
                        std::cout << i << " ";
                    }
                    std::cout << "; ";
                }
                std::cout << "\n";
            }
        }
    }

    uint64_t max{0};
    for(auto& [total, values] : results)
    {
        for(auto& magic3gon : values)
        {
            std::string concat{};
            concat.reserve(32);

            for(auto line : magic3gon)
            {
                for(auto i : line)
                {
                    concat += std::to_string(i);
                }
            }

            // The problem states it wants the maximum 16 digit number.
            if(concat.length() != 16)
            {
                continue;
            }

            uint64_t value = std::stoul(concat);

            max = std::max(value,  max);
        }
    }

    return max;
}

int main()
{
    std::cout << magic5gonring(false);
    return 0;
}
