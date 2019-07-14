#pragma once
#include <string>
#include <string_view>
#include <type_traits>

/**
 *  Convert a string containing a binary representation of a number into
 *  this computable number of specified type.
 *  Characters other than 0 and 1 are ignored.
 */
template <typename T>
T from_binary(std::string_view str_bin) noexcept
{
    auto value = 0ULL;
    auto counter = 0ULL;

    for (auto it =str_bin.crbegin(); it != str_bin.crend(); it = std::next(it))
    {
        if (*it == '1') {
            value |= (1ULL << counter);
            ++counter;
        }
        else if (*it == '0')
            ++counter;
    }

    return static_cast<T>(value);
}
