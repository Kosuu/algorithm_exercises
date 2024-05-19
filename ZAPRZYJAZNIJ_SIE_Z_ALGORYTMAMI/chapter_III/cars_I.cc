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
 * Rozdział III - Sumy prefiksowe
 * Zadanie: Samochody
 */

template <typename T> 
[[maybe_unused]] std::vector<T> computePrefixSums(const std::vector<T>& numberList)
{
    std::vector<T> prefixSums(numberList.size() + 1, T{});
    for (auto i = 1U; i <= numberList.size(); i++)
        prefixSums[i] = prefixSums[i - 1] + numberList[i - 1];

    return prefixSums; 
}

template <typename T>
[[maybe_unused]] T getSumOfARange(const std::vector<T>& prefixSums, std::uint32_t x, std::uint32_t y)
{
    return prefixSums[y + 1] - prefixSums[x];
}

int main()
{
    std::uint32_t n;
    std::cin >> n;
    std::vector<std::uint32_t> directions;

    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, n , std::back_inserter(directions));
    
    std::uint32_t eastDirectionCars{};
    std::uint64_t countedPairs{};
    
    for (const auto direction : directions)
    {
        if (direction == 0U)
            eastDirectionCars++;
        else //driving west
            countedPairs += eastDirectionCars;
    }

    std::cout << countedPairs << std::endl;

    return EXIT_SUCCESS;
}
