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
 * Zadanie: Railroad Tracks
 */

using Houses = std::vector<std::pair<std::uint64_t, std::uint64_t>>;

template <typename T> 
[[maybe_unused]] void merge(std::vector<T>& numberList, const std::uint32_t startPos,
const std::uint32_t mid, const std::uint32_t endPos)
{
    const std::int32_t sizeLeftSide = mid - startPos + 1U;
    const std::int32_t sizeRightSide = endPos - mid;
    std::vector<T> leftSide(sizeLeftSide), rightSide(sizeRightSide);

    //Fill sub arrays with data 
    for (auto i = 0; i < sizeLeftSide; ++i)
        leftSide[i] = numberList[startPos + i];
    for (auto i = 0; i < sizeRightSide; ++i)
        rightSide[i] = numberList[mid + 1 + i];
    
    auto leftSideIdx{0}, rightSideIdx{0};
    auto mergedArrayIdx{startPos};

    //Merge sub arrays into main array
    while ((leftSideIdx < sizeLeftSide) && (rightSideIdx < sizeRightSide))
    {
        if (leftSide[leftSideIdx] <= rightSide[rightSideIdx])
            numberList[mergedArrayIdx++] = leftSide[leftSideIdx++];
        else
            numberList[mergedArrayIdx++] = rightSide[rightSideIdx++];
    }

    //Empty left sub array
    while (leftSideIdx < sizeLeftSide)
        numberList[mergedArrayIdx++] = leftSide[leftSideIdx++];

    //Empty right sub array
    while (rightSideIdx < sizeRightSide)
        numberList[mergedArrayIdx++] = rightSide[rightSideIdx++];
}

template <typename T> 
[[maybe_unused]] void doMergeSort(std::vector<T>& numberList, const std::uint32_t startPos, const std::uint32_t endPos)
{
    if (startPos >= endPos)
        return;

    auto mid = startPos + (endPos - startPos) / 2;
    doMergeSort(numberList, startPos, mid);
    doMergeSort(numberList, mid + 1, endPos);
    merge(numberList, startPos, mid, endPos);
}

int main()
{
    Houses input;
    std::uint32_t n{};
    std::uint64_t x{}, y{};
    
    std::cin >> n;
    for (auto i = 0U; i < n; ++i)
    {
        std::cin >> x >> y;
        input.emplace_back(std::make_pair(x, y));
    }
#ifdef MERGE_SORT
    if (input.size() > 0)
        doMergeSort(input, 0, input.size() - 1U);
#else
    std::sort(input.begin(), input.end());
#endif
    std::uint64_t result{std::numeric_limits<std::uint64_t>::max()}, distance{input[0].second};
    for (auto i = 1U; i < n; ++i)
    {
        distance += input[i].first - input[i - 1].first;
        result = std::min(result, distance + input[i].second);
        distance = std::min(distance, input[i].second);
    }

    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}
