#include <iostream>
#include <cmath>
#include <cstdint>

/*
 * Zaprzyjaźnij się z algorytmami, J.Tomasiewicz
 * Rozdział I - Żłożoność czasowa
 * Zadanie: Żabka
 */

int main()
{
    std::uint32_t x, y, s;
    std::cin >> x >> y >> s;

    const std::int32_t jumps = std::ceil((y - x) / static_cast<double>(s));
    std::cout << jumps << std::endl; 

    return EXIT_SUCCESS;
}
