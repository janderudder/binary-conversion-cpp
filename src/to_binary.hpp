#pragma once
#include <climits>
#include <cstdint>
#include <string>
#include <string_view>

/**
 *  Get binary representation (as a string) of a numeric value,
 *  no delimiter specified.
 */
template <typename T>
std::string to_binary(T val, std::size_t const bit_len =sizeof(T)*CHAR_BIT)
{
    std::string inv_binary;

    for (std::size_t i=0; i < bit_len; ++i)
    {
        inv_binary += (static_cast<std::uint64_t>(val) >> i) & 1 ? '1' : '0';
    }

    return {inv_binary.crbegin(), inv_binary.crend()};
}

/**
 *  Get binary representation (as a string) of a numeric value,
 *  with a delimiter between bytes.
 */
template <typename T>
std::string to_binary(
    T                   val,
    std::string_view    byte_delim,
    std::size_t const   bit_len     =sizeof(T)*CHAR_BIT
){
    std::string         inv_binary;
    std::string const   inv_delim   {byte_delim.crbegin(), byte_delim.crend()};

    for (std::size_t i=0; i < bit_len; ++i)
    {
        if (i % CHAR_BIT == 0)
            inv_binary += inv_delim;

        inv_binary += (static_cast<std::uint64_t>(val) >> i) & 1 ? '1' : '0';
    }

    return {
        inv_binary.crbegin(),
        inv_binary.crend() - byte_delim.length()    // remove tail delimiter
    };
}
