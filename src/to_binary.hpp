#pragma once
#include <algorithm>
#include <climits>
#include <cstdint>
#include <string>
#include <string_view>

/**
 *  Get a binary representation of a numeric value, as a string.
 *  No delimiter specified.
 */
template <typename T>
std::string to_binary(T val, std::size_t const bit_len =sizeof(T)*CHAR_BIT)
{
    std::string         inv_binary;
    std::size_t const   useful_len = std::min(sizeof(T)*CHAR_BIT, bit_len);

    for (std::size_t i=0; i < useful_len; ++i)
    {
        inv_binary += (static_cast<std::uint64_t>(val) >> i) & 1 ? '1' : '0';
    }

    // Add front zeros if user requested a string size bigger than type size
    inv_binary.append(bit_len-useful_len, '0');

    return {inv_binary.crbegin(), inv_binary.crend()};
}

/**
 *  Get a binary representation of a numeric value, as a string
 *  with a delimiter between bytes.
 */
template <typename T>
std::string to_binary(
    T                   val,
    std::string_view    byte_delim,
    std::size_t const   bit_len     =sizeof(T)*CHAR_BIT
)
{
    std::string         inv_binary;
    std::string const   inv_delim   {byte_delim.crbegin(), byte_delim.crend()};
    std::size_t const   useful_len = std::min(sizeof(T)*CHAR_BIT, bit_len);

    for (std::size_t i=0; i < useful_len; ++i)
    {
        if (i % CHAR_BIT == 0)
            inv_binary += inv_delim;

        inv_binary += (static_cast<std::uint64_t>(val) >> i) & 1 ? '1' : '0';
    }

    // Add front zeros if user requested a string size bigger than type size
    for (std::size_t i=0; i < bit_len-useful_len; ++i)
    {
        if (i % CHAR_BIT == 0)
            inv_binary += inv_delim;

        inv_binary += '0';
    }

    return {
        inv_binary.crbegin(),
        inv_binary.crend() - byte_delim.length()    // remove tail delimiter
    };
}
