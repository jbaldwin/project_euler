#pragma once

#include <array>
#include <vector>
#include <functional>

namespace lib
{

template<typename DataType, size_t DataLength>
auto _permutate(
    const std::array<DataType, DataLength>& prefix,
    const std::array<DataType, DataLength>& data,
    size_t idx,
    size_t remaining,
    std::function<void(const std::array<DataType, DataLength>&)>& callback
) -> void
{
    if(remaining == 0)
    {
        callback(prefix);
    }
    else
    {
        for(size_t i = 0; i < remaining; ++i)
        {
            std::array<DataType, DataLength> new_prefix = prefix;
            new_prefix[idx] = data[i];

            std::array<DataType, DataLength> new_data{};
            bool i_found{false};
            for(size_t j = 0; j < remaining; ++j)
            {
                if(j == i)
                {
                    i_found = true;
                }
                new_data[j] = (i_found) ? data[j + 1] : data[j];
            }

            _permutate(new_prefix, new_data, idx + 1, remaining - 1, callback);
        }
    }
}

template<typename DataType, size_t DataLength>
auto permutate(
    const std::array<DataType, DataLength>& data,
    std::function<void(const std::array<DataType, DataLength>&)> callback
) -> void
{
    std::array<DataType, DataLength> empty_prefix{};
    _permutate<DataType, DataLength>(empty_prefix, data, 0, DataLength, callback);
}

template<typename DataType>
auto _permutate(
    const std::vector<DataType>& prefix,
    const std::vector<DataType>& data,
    size_t idx,
    size_t remaining,
    std::function<void(const std::vector<DataType>&)>& callback
) -> void
{
    if(remaining == 0)
    {
        callback(prefix);
    }
    else
    {
        for(size_t i = 0; i < remaining; ++i)
        {
            std::vector<DataType> new_prefix = prefix;
            new_prefix[idx] = data[i];

            std::vector<DataType> new_data{};
            new_data.resize(prefix.size(), 0);
            bool i_found{false};
            for(size_t j = 0; j < remaining; ++j)
            {
                if(j == i)
                {
                    i_found = true;
                }
                new_data[j] = (i_found) ? data[j + 1] : data[j];
            }

            _permutate(new_prefix, new_data, idx + 1, remaining - 1, callback);
        }
    }
}

template<typename DataType>
auto permutate(
    const std::vector<DataType>& data,
    std::function<void(const std::vector<DataType>&)> callback
) -> void
{
    std::vector<DataType> empty_prefix{};
    empty_prefix.resize(data.size(), 0);
    _permutate<uint64_t>(empty_prefix, data, 0, data.size(), callback);
}

/**
 * Determines if a and b are permutations of each other.
 */
bool is_permutation(uint64_t a, uint64_t b)
{
    std::array<uint64_t, 10> count_a{};
    std::array<uint64_t, 10> count_b{};

    do { ++count_a[a % 10]; } while (a /= 10);
    do { ++count_b[b % 10]; } while (b /= 10);

    return count_a == count_b;
}

} // namespace lib
