#include <iostream>
#include <functional>
#include <charconv>
#include <string_view>
#include <optional>
#include <cstdint>

/*
 * Zaprzyjaźnij się z algorytmami, J.Tomasiewicz
 * Rozdział I - Żłożoność czasowa
 * Zadanie: Żabka
 */

namespace
{
constexpr auto kArgumentsExpectedCount = 4;

static constexpr std::array<std::uint32_t, 10> pow10 = {
    1, 10, 100, 1000, 10000, 
    100000, 1000000, 10000000, 100000000, 1000000000
};

template<typename T>
std::optional<T> convert(std::string_view inputParam, std::function<bool(const T)> validator)
{
    T value;
    auto [ptr, ec] = std::from_chars(inputParam.data(), inputParam.data() + inputParam.size(), value);
    if ((ec != std::errc()) or not validator(value))
    {
        std::cout << "USAGE!" << std::endl;
        return {};
    }

    return value;
}
}

int main(int argc, char** argv)
{
    if (argc != kArgumentsExpectedCount)
        return EXIT_FAILURE;

    auto x = convert<std::uint32_t>(argv[1], [](const auto param){ return param >= 1U; });
    if (not x)
        return EXIT_FAILURE;

    auto y = convert<std::uint32_t>(argv[2], [&x](const auto param){ return (param > *x && param <= pow10[9]); });
    auto s = convert<std::uint32_t>(argv[3], [&x](const auto param){ return (param > *x && param <= pow10[9]); });

    if (not y or not s)
        return EXIT_FAILURE;

    auto jumps{0U};
    for (; *x < *y; ++jumps)
    {
        *x += *s;
    }

    std::cout << jumps << std::endl; 

    return EXIT_SUCCESS;
}
