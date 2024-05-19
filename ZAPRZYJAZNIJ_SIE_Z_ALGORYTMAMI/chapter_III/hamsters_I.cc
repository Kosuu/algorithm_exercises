#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include <limits>
#include <numeric>
#include <iomanip>

/*
 * Zaprzyjaźnij się z algorytmami, J.Tomasiewicz
 * Rozdział III - Sumy prefiksowe
 * Zadanie: Chomiki
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
[[maybe_unused]] std::vector<T> computePrefixSums(const std::vector<T>& numberList, const T element)
{
    std::vector<T> prefixSums(numberList.size() + 1, T{});
    for (auto i = 1U; i <= numberList.size(); i++)
    {
        auto currentValue{0U};
        if (numberList[i - 1] == element)
            currentValue = numberList[i - 1];
        
        prefixSums[i] = prefixSums[i - 1] + currentValue;
    }

    return prefixSums; 
}

template <typename T>
[[maybe_unused]] T getSumOfARange(const std::vector<T>& prefixSums, std::uint32_t x, std::uint32_t y)
{
    return prefixSums[y] - prefixSums[x - 1];
}

int main()
{
    using SubsetRange = std::pair<std::uint32_t, std::uint32_t>;

    std::uint32_t n{}, m{};
    std::cin >> n >> m;
    std::vector<std::uint32_t> hamsters;
    std::vector<SubsetRange> subsets;

    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, n , std::back_inserter(hamsters));
    for (auto i = 0; i < m; i++)
    {
        std::uint32_t a{}, b{};
        std::cin >> a >> b;
        subsets.emplace_back(std::make_pair(a, b));
    }

    std::map<std::uint16_t, std::vector<std::uint32_t>> prefixSums;
    for (auto i = 1U; i <= 5; i++)
        prefixSums[i] = computePrefixSums(hamsters, i);
 
    for (const auto range : subsets)
    {
        for (auto i = 1U; i <= 5; i++)
        {
            if (getSumOfARange(prefixSums[i], range.first, range.second) > 0)
            {
                std::cout << i << std::endl;
                break;            
            }
        }
    }

    return EXIT_SUCCESS;
}
