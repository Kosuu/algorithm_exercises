#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <iterator>
#include <limits>
#include <numeric>

/*
 * Zaprzyjaźnij się z algorytmami, J.Tomasiewicz
 * Rozdział II - Zliczanie elementów
 * Zadanie: Permutacja
 */

int main()
{
    std::uint32_t n;
    std::vector<std::uint32_t> numbers;

    std::cin >> n;
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, n , std::back_inserter(numbers));

    auto result{"NIE"};
    std::vector<std::uint32_t> countedNumbers(n + 1, 0);
    for (const auto number : numbers) {
        if(number <= n) countedNumbers[number]++;
        else {
            std::cout << result << std::endl;
            return EXIT_SUCCESS;
        }
    }
    auto invalidNumber = std::find_if(std::next(countedNumbers.begin()), countedNumbers.end(), [](const auto& count) {return (count != 1);});
    result = (invalidNumber != countedNumbers.end()) ? "NIE" : "TAK";

    std::cout << result << std::endl;
    return EXIT_SUCCESS;
}
