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
 * Zadanie: Ropucha
 */

int main()
{
    std::uint32_t n, m;
    std::vector<std::uint32_t> leafs;

    std::cin >> n >> m;
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, m , std::back_inserter(leafs));

    auto result{-1};
    auto minLeafLeftCount{n};

    std::vector<std::uint32_t> countedLeafs(n + 1, 0);
    for (auto i = 0; i < m; ++i) {
        if (countedLeafs[leafs[i]] == 0) {
            minLeafLeftCount--;
        }
        if (minLeafLeftCount == 0) {
            result = i + 1;
            break;
        }
        countedLeafs[leafs[i]]++;
    }

    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}
