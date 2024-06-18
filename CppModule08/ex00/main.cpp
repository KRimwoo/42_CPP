#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::cout << "Find value in vector " << std::endl;
    std::vector<int> intVector;
    for (int i = 0; i < 10; i++)
        intVector.push_back(i);
    try {
        std::cout << "Value found at index: " << *easyfind(intVector, 5) << std::endl;
        std::cout << "Value found at index: " << *easyfind(intVector, 9) << std::endl;
        std::cout << "Value found at index: " << *easyfind(intVector, 20) << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Find value in list " << std::endl;
    std::list<int> intList;
    for (int i = 0; i < 10; i++)
        intList.push_back(i);
    try {
        std::cout << "Value found at index: " << *easyfind(intList, 1) << std::endl;
        std::cout << "Value found at index: " << *easyfind(intList, 3) << std::endl;
        std::cout << "Value found at index: " << *easyfind(intList, 10) << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}