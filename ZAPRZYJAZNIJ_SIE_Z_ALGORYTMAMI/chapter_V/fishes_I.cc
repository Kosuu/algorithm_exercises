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
 * Rozdział V - Stos i kolejka
 * Zadanie: Ryby
 */

constexpr auto MAX_SIZE = 1'000'000;

template <typename T>
class Stack final
{
public:
    void push(const T byte)
    {
        mData[mSize] = byte;
        mSize++;
    }
    T pop()
    {
        mSize--;
        return mData[mSize];
    }
    T top() const
    {
        return mData[mSize - 1U];
    }
    std::size_t size() const
    {
        return mSize;
    }
private:
    T mData[MAX_SIZE];
    std::size_t mSize{0U};
};

int main()
{
    std::uint32_t n;
    std::cin >> n;
    std::vector<std::uint64_t> fishSizes;
    std::vector<std::uint16_t> fishDirections;

    std::copy_n(std::istream_iterator<std::uint64_t>{std::cin}, n , std::back_inserter(fishSizes));
    std::copy_n(std::istream_iterator<std::uint16_t>{std::cin}, n , std::back_inserter(fishDirections));

    Stack<std::uint64_t> stack;
    std::uint32_t result{0U};
    for (auto i = 0U; i < n; ++i)
    {
        if (fishDirections[i] == 1) stack.push(fishSizes[i]);
        else if (stack.size() == 0U) result += 1U;
        else
        {
            while (fishSizes[i] > stack.top())
            {
                static_cast<void>(stack.pop());
            }
            if (stack.size() == 0U) result += 1U;
        }
    }
    result += stack.size();

    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}
