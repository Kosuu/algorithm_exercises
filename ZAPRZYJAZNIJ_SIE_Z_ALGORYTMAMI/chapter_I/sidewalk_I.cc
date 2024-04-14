#include <iostream>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <iterator>
#include <limits>

/*
 * Zaprzyjaźnij się z algorytmami, J.Tomasiewicz
 * Rozdział I - Żłożoność czasowa
 * Zadanie: Chodnik
 */

int main()
{
    std::uint32_t n;
    std::vector<std::uint32_t> numbers;

    std::cin >> n;
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, (n - 1) , std::back_inserter(numbers));

    auto lowest{std::numeric_limits<std::uint32_t>::max()};
    auto greatest{std::numeric_limits<std::uint32_t>::min()};
    auto collectionSum{0U};

    std::for_each(numbers.begin(), numbers.end(), [&lowest, &greatest, &collectionSum](const auto number) {
        if (lowest > number) lowest = number;
        if (greatest < number) greatest = number;
        collectionSum += number;
    });

    auto expectedSum{0U};
    for (auto i = lowest; i <= greatest; ++i)
        expectedSum += i;
    
    std::cout << (expectedSum - collectionSum) << std::endl; 

    return EXIT_SUCCESS;
}
