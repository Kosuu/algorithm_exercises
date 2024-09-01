#include <iostream>
#include <cstdint>
#include <algorithm>
#include <map>
#include <iterator>
#include <limits>
#include <numeric>
#include <iomanip>

/*
 * Zaprzyjaźnij się z algorytmami, J.Tomasiewicz
 * Rozdział V - Stos i kolejka
 * Zadanie: Nawiasy
 */

constexpr auto MAX_SIZE = 250U;

constexpr bool isLeftSide(const std::uint8_t byte)
{
    return (byte == '{') or (byte == '[') or (byte == '(');
}

std::uint8_t reverse(const std::uint8_t byte)
{
    static std::map<std::uint8_t, std::uint8_t> brackets = {{'{', '}'}, {'[', ']'}, {'(', ')'},
                                                            {'}', '{'}, {']', '['}, {')', '('}};
    return brackets[byte];
}

class Stack final
{
public:
    void push(const std::uint8_t byte)
    {
        mData[mSize] = byte;
        mSize++;
    }
    std::uint8_t pop()
    {
        mSize--;
        return mData[mSize];
    }
    std::size_t size()
    {
        return mSize;
    }
private:
    std::uint8_t mData[MAX_SIZE];
    std::size_t mSize{0U};
};

int main()
{
    std::uint16_t n;
    std::cin >> n;
    std::stringstream result{};

    for (auto i = 0U; i < n; ++i)
    {
        std::string input;
        std::cin >> input;

        Stack stack;
        bool stringInvalid{false};
        for (const auto& byte : input)
        {
            if (isLeftSide(byte)) stack.push(byte);
            else
            {
                const auto isRightSideValid = (stack.size() > 0U) and (stack.pop() == reverse(byte));
                if (not isRightSideValid)
                {
                    stringInvalid = true;
                    break;
                }
            }
        }

        if (not stringInvalid and stack.size() == 0U) result << "TAK" << std::endl;
        else result << "NIE" << std::endl;
    }

    std::cout << result.str();

    return EXIT_SUCCESS;
}
