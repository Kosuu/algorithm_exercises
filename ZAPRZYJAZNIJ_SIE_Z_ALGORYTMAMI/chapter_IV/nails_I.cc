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
 * Zadanie: Nails
 */

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
    std::vector<std::uint32_t> input;
    std::int32_t n{}, k{};
    
    std::cin >> n;
    std::cin >> k;
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, n , std::back_inserter(input));
#ifdef MERGE_SORT
    if (input.size() > 0)
        doMergeSort(input, 0, input.size() - 1U);
#else
    std::sort(input.begin(), input.end());
#endif
    std::int32_t maxCount{}, counter{};
    for (std::int32_t i = 0; i < n - k - 1; ++i)
    {
        if (input[i] == input[i + 1])
            counter++;
        else
            counter = 0;
        maxCount = std::max(maxCount, counter); 
    }

    auto result = std::min(n, maxCount + k + 1);
    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}
