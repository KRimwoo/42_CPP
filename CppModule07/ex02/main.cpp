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
        std::cout << "\nintArray_copied: " << std::endl;
        std::cout  << "size: " << intArray_copied.size() << std::endl;
        for (unsigned int idx = 0; idx < intArray_copied.size(); idx++)
            std::cout << intArray_copied[idx] << " ";
        std::cout << std::endl;
        
        std::cout << "\nAccessing out of range" << std::endl;
        std::cout << intArray[10] << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Array <char> charArray(5);
        for (unsigned int idx = 0; idx < charArray.size(); idx++)
            charArray[idx] = 'a' + idx;

        std::cout << "\ncharArray: " << std::endl;
        std::cout << "size: " << charArray.size() << std::endl;
        for (unsigned int idx = 0; idx < charArray.size(); idx++)
            std::cout << charArray[idx] << " ";
        std::cout << std::endl;

        const Array <char> charArray_copied(charArray);
        std::cout << "\ncharArray_copied: " << std::endl;
        std::cout << "size: " << charArray_copied.size() << std::endl;
        for (unsigned int idx = 0; idx < charArray_copied.size(); idx++)
            std::cout << charArray_copied[idx] << " ";
        std::cout << std::endl;

        std::cout << "\nAccessing out of range" << std::endl;
        std::cout << charArray[-1] << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Array <float> floatArray(0);
        for (unsigned int idx = 0; idx < floatArray.size(); idx++)
            floatArray[idx] = idx + 0.1;

        std::cout << "\nAccessing out of range" << std::endl;
        std::cout << floatArray[10] << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
