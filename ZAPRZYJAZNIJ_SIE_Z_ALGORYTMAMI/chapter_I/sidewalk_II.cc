#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>

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

    auto collectionSum = std::accumulate(numbers.begin(), numbers.end(), 0U);

    auto expectedSum = ((n * (n + 1)) / 2);
    auto result = expectedSum - collectionSum;
    
    std::cout << result << std::endl; 

    return EXIT_SUCCESS;
}
