#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::cout << "Find int value in vector " << std::endl;
    std::vector<int> intVector;
    for (int i = 0; i < 10; i++)
        intVector.push_back(i);
    try {
        std::vector<int>::iterator iter = easyfind(intVector, 1);
        std::cout << "Value found: " << *iter << std::endl;
        iter = easyfind(intVector, 3);
        std::cout << "Value found: " << *iter << std::endl;
        iter = easyfind(intVector, 10);
        std::cout << "Value found: " << *iter << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\nFind char value in list " << std::endl;
    std::list<char> intList;
    for (int i = 0; i < 10; i++)
        intList.push_back('a' + i);
    try {
        std::list<char>::iterator iter = easyfind(intList, 'a');
        std::cout << "Value found: " << *iter << std::endl;
        iter = easyfind(intList, 'c');
        std::cout << "Value found: " << *iter << std::endl;
        iter = easyfind(intList, 'k');
        std::cout << "Value found: " << *iter << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}