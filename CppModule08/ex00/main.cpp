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

    std::cout << "\nFind value in list " << std::endl;
    std::list<int> intList;
    for (int i = 0; i < 10; i++)
        intList.push_back(i + 10);
    try {
        std::list<int>::iterator iter = easyfind(intList, 12);
        std::cout << "Value found: " << *iter << std::endl;
        iter = easyfind(intList, 14);
        std::cout << "Value found: " << *iter << std::endl;
        iter = easyfind(intList, 3);
        std::cout << "Value found: " << *iter << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}