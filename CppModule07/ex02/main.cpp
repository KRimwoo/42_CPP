#include "Array.hpp"


int main()
{
    try {
        Array<int> intArray(5);
        for (unsigned int idx = 0; idx < intArray.size(); idx++)
            intArray[idx] = idx;
        
        std::cout << "intArray: " << std::endl;
        std::cout << "size: " << intArray.size() << std::endl;
        for (unsigned int idx = 0; idx < intArray.size(); idx++)
            std::cout << intArray[idx] << " ";
        std::cout << std::endl;

        Array<int> intArray_copied = intArray;
        std::cout << "intArray_copied: " << std::endl;
        std::cout  << "size: " << intArray_copied.size() << std::endl;
        for (unsigned int idx = 0; idx < intArray_copied.size(); idx++)
            std::cout << intArray_copied[idx] << " ";
        std::cout << std::endl;
        
        std::cout << "Accessing out of range" << std::endl;
        std::cout << intArray[10] << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Array <char> charArray(5);
        for (unsigned int idx = 0; idx < charArray.size(); idx++)
            charArray[idx] = 'a' + idx;

        std::cout << "charArray: " << std::endl;
        std::cout << "size: " << charArray.size() << std::endl;
        for (unsigned int idx = 0; idx < charArray.size(); idx++)
            std::cout << charArray[idx] << " ";
        std::cout << std::endl;

        const Array <char> charArray_copied(charArray);
        std::cout << "charArray_copied: " << std::endl;
        std::cout << "size: " << charArray_copied.size() << std::endl;
        for (unsigned int idx = 0; idx < charArray_copied.size(); idx++)
            std::cout << charArray_copied[idx] << " ";
        std::cout << std::endl;

        // std::cout << "Accessing out of range" << std::endl;
        // std::cout << charArray[-1] << std::endl;

        Array <char> charArray_empty(0);
        charArray_empty = charArray;

        std::cout << "charArray_empty: " << std::endl;
        std::cout << "size: " << charArray_empty.size() << std::endl;
        for (unsigned int idx = 0; idx < charArray_empty.size(); idx++)
            std::cout << charArray_empty[idx] << " ";
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}