#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <iterator>
#include <limits>
#include <numeric>

/*
 * Zaprzyjaźnij się z algorytmami, J.Tomasiewicz
 * Rozdział I - Żłożoność czasowa
 * Zadanie: Taśma
 */

int main()
{
    std::uint32_t n;
    std::vector<std::int16_t> numbers;

    std::cin >> n;
    std::copy_n(std::istream_iterator<std::int16_t>{std::cin}, n , std::back_inserter(numbers));

    auto sum = std::accumulate(numbers.begin(), numbers.end(), 0);;
    auto minDiffAbs{std::numeric_limits<std::uint32_t>::max()};
    auto leftSide{0}; 
    auto rightSide{0}; 
    for (auto i = 0; i < numbers.size() - 1; ++i)
    {
        leftSide += numbers[i];
        rightSide = sum - leftSide;
        std::uint32_t diffAbs = std::abs(leftSide - rightSide);
        minDiffAbs = std::min(minDiffAbs, diffAbs);
    }
    
    std::cout << minDiffAbs << std::endl; 

    return EXIT_SUCCESS;
}
