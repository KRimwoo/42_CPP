#include "iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    char charArray[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};

    iter(intArray, 5, print);
    std::cout << std::endl;
    iter(floatArray, 6, print);
    std::cout << std::endl;
    iter(charArray, 13, print);
    std::cout << std::endl;
    return 0;
}
