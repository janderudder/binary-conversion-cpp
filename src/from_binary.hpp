#pragma once
#include <string>
#include <string_view>

/**
 *  Convert a binary representation -a string- into a computable number.
 *  Characters other than 0 and 1 are ignored.
 */
template <typename T>
T from_binary(std::string_view str_bin) noexcept
{
    std::uint64_t value = 0;
    std::string str_inv_bin {str_bin.crbegin(), str_bin.crend()};

    for (std::size_t i=0; i < str_inv_bin.length(); ++i)
    {
        if (str_inv_bin[i] == '1')
            value |= (std::uint64_t{1} << i);
    }

    return static_cast<T>(value);
}
