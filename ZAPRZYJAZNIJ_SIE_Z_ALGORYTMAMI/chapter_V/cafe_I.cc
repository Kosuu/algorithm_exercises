#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <iterator>
#include <limits>
#include <numeric>
#include <iomanip>

/*
 * Zaprzyjaźnij się z algorytmami, J.Tomasiewicz
 * Rozdział V - Stos i kolejka
 * Zadanie: Cukiernia
 */

int main()
{
    std::uint32_t n;
    std::cin >> n;
    std::vector<std::uint64_t> prices;

    std::copy_n(std::istream_iterator<std::uint64_t>{std::cin}, n , std::back_inserter(prices));

    std::uint64_t result{0U};
    std::uint64_t min = prices[n - 1] + 1U;

    for (std::int32_t i = n - 1; i >= 0; --i)
    {
        if (prices[i] < min) min = prices[i];
        result += min;
    }

    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}
