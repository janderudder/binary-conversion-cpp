#include <iostream>
#include <cstddef>
#include "to_binary.hpp"
#include "from_binary.hpp"


int main()
{
    const char* delim = "'";

    std::uint8_t            ui8             {1};
    std::int_fast64_t       fasti64         {2};
    std::byte               byte            {3};
    char                    c               {4};
    std::size_t             ull             {5};
    float                   f               {6.1f};
    double                  dbl             {7.2};

    auto const b_ui8        = to_binary(ui8, delim);
    auto const b_fasti64    = to_binary(fasti64, delim);
    auto const b_byte       = to_binary(byte);
    auto const b_c          = to_binary(c, delim);
    auto const b_ull        = to_binary(ull, delim);
    auto const b_f          = to_binary(f, delim);
    auto const b_dbl        = to_binary(dbl, delim);

    std::cout << "ui8:\t"   << b_ui8        << "\n";
    std::cout << "fasti64:" << b_fasti64    << "\n";
    std::cout << "byte\t"   << b_byte       << "\n";
    std::cout << "c\t"      << b_c          << "\n";
    std::cout << "ull\t"    << b_ull        << "\n";
    std::cout << "f\t"      << b_f          << "\n";
    std::cout << "dbl\t"    << b_dbl        << "\n";

    std::cout
        << static_cast<unsigned>(from_binary<std::uint8_t>(b_ui8))  << "\n";
    std::cout
        << from_binary<std::int_fast64_t>(b_fasti64)                << "\n";
    std::cout
        << static_cast<unsigned>(from_binary<std::byte>(b_byte))     << "\n";
    std::cout
        << static_cast<unsigned>(from_binary<char>(b_c))        << "\n";
    std::cout
        << static_cast<std::size_t>(from_binary<std::size_t>(b_ull))   << "\n";
    std::cout
        << from_binary<float>(b_f)           << "\n";
    std::cout
        << from_binary<double>(b_dbl)        << "\n";

}
