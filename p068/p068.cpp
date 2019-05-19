#include <iostream>
#include <array>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>
#include <numeric>

#include <lib/Permutations.hpp>
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
            std::array<std::array<int, 3>, 5> lines{
                std::array<int, 3>{p[0], p[1], p[2]},
                std::array<int, 3>{p[3], p[2], p[4]},
                std::array<int, 3>{p[5], p[4], p[6]},
                std::array<int, 3>{p[7], p[6], p[8]},
                std::array<int, 3>{p[9], p[8], p[1]}
            };

            std::array<uint64_t, 5> totals{sum(lines[0]), sum(lines[1]), sum(lines[2]), sum(lines[3]), sum(lines[4])};

            if(
                   totals[0] == totals[1]
                && totals[0] == totals[2]
                && totals[0] == totals[3]
                && totals[0] == totals[4]
            )
            {
                // We've got a valid combo!

                // Find the lowest first char for ordering of the lines per problem requirements.
                size_t start_idx{0};
                int min_value = std::numeric_limits<int>::max();
                for(size_t i = 0; i < 5; ++i)
                {
                    if(lines[i][0] < min_value)
                    {
                        min_value = lines[i][0];
                        start_idx = i;
                    }
                }

                std::array<std::array<int, 3>, 5> result{};
                for(size_t i = 0; i < 5; ++i, ++start_idx)
                {
                    result[i] = lines[start_idx % 5];
                }

                auto& sets = results[totals[0]];
                sets.insert(result);
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

/**
 * Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.
 *
 * 4
 *     3
 *   1  2  6
 * 5
 *
 * Working clockwise, and starting from the group of three with the numerically lowest external node (4,3,2 in this example),
 * each solution can be described uniquely.  For example, the above solution can be described by the set: 4,3,2; 6,2,1;, 5,1,3.
 *
 * It is possible to complete the ring with four different totals: 9, 10, 11, and 12.  There are eight solutions in total.
 *
 * Total    Solution Set
 * 9        4,2,3; 5,3,1; 6,1,2
 * 9        4,3,2; 6,2,1; 5,1,3
 * 10       2,3,5; 4,5,1; 6,1,3
 * 10       2,5,3; 6,3,1; 4,1,5
 * 11       1,4,6; 3,6,2; 5,2,4
 * 11       1,6,4; 5,4,2; 3,2,6
 * 12       1,5,6; 2,6,4; 3,4,5
 * 12       1,6,5; 3,5,4; 2,4,6
 *
 * By concatenating each group it is possible to form 9-digit strings; the maximum string for a 3-gon ring is 432621513.
 *
 * Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16- and 17-digit strings.  What is the
 * maximum 16-digit string for a "magic" 5-gon ring?
 *
 *
 * *Developer Notes*
 * The line ordering is as follows: (this is not a valid magic 5 gon, just the line index ordering).
 * 1,2,3; 4,3,5; 6,5,7; 8,7,9; 10,9,2
 */
int main()
{
    std::cout << magic5gonring(false);
    return 0;
}
