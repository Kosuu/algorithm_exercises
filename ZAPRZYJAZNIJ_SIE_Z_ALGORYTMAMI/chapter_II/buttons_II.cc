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
 * Zadanie: Przyciski
 */

int main()
{
    std::uint32_t n, m;
    std::cin >> n >> m;
    auto premiumButton{n + 1U};
    std::vector<std::uint32_t> buttonsList;

    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, m , std::back_inserter(buttonsList));

    std::vector<std::uint32_t> countedButtons(premiumButton, 0);

    auto lowestValue{0U};
    auto highestValue{0U};
    for (auto i = 0; i < m; ++i) {
        if (buttonsList[i] == premiumButton) {
            lowestValue = highestValue;
        }
        else {
            countedButtons[buttonsList[i]] = std::max(lowestValue, countedButtons[buttonsList[i]]) +1 ;
            highestValue = std::max(highestValue, countedButtons[buttonsList[i]]);
        }
    }

    for (auto i = 1U; i < countedButtons.size(); ++i)
    {
        countedButtons[i] = std::max(lowestValue, countedButtons[i]);
        std::cout << countedButtons[i] << ' ';
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
