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
 * Rozdział IV - Sortowanie
 * Zadanie: Iloczyn
 */

constexpr auto kMaxRange = 1000U;

template <typename T> 
[[maybe_unused]] void doCountingSort(std::vector<T>& numberList)
{ 
    uint32_t negativeNumbersCounting[kMaxRange + 1U] {0};
    uint32_t positiveNumbersCounting[kMaxRange + 1U] {0};
    for (auto i = 0U; i < numberList.size(); ++i)
    {
        if (numberList[i] < 0) negativeNumbersCounting[std::abs(numberList[i])]++;
        else positiveNumbersCounting[numberList[i]]++;
    }

    numberList.clear();
    for (auto i = kMaxRange; i > 0; --i)
    {
        for (auto j = 1; j <= negativeNumbersCounting[i]; ++j)
            numberList.push_back(-i);
    }

    for (auto i = 0U; i <= kMaxRange; ++i)
    {
        for (auto j = 1; j <= positiveNumbersCounting[i]; ++j)
            numberList.push_back(i);
    } 
}

int main()
{
    std::uint16_t z;
    std::cin >> z;
    std::vector<std::vector<std::int32_t>> inputs(z);
    std::vector<std::int32_t> products(z);

    for (auto i = 0U; i < z; ++i)
    {
        std::uint32_t n;
        std::cin >> n;
        std::copy_n(std::istream_iterator<std::int32_t>{std::cin}, n , std::back_inserter(inputs[i]));
#ifdef COUNTING_SORT
        doCountingSort(inputs[i]);
#else
        std::sort(inputs[i].begin(), inputs[i].end());
#endif
        const auto& sortedInput = inputs[i];  
        auto lastElement = sortedInput.size() - 1U;
        auto positiveMax = sortedInput[lastElement] * sortedInput[lastElement - 1U] * sortedInput[lastElement - 2U];
        auto negativeMax = sortedInput[0] * sortedInput[1] * sortedInput[lastElement];
        products[i] = std::max(positiveMax, negativeMax);
    }

    for (const auto product : products)
        std::cout << product << std::endl;

    return EXIT_SUCCESS;
}
