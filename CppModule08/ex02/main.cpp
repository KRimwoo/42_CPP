#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.pop();
    mstack.push(4);
    mstack.push(5);
    mstack.pop();
    mstack.push(6);
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator it_end = mstack.end();

    while (it != it_end) {
        std::cout << *it << " ";
        *it += 1;
        ++it;
    }
    std::cout << std::endl << std::endl;

    MutantStack<int> const copied_mstack = mstack;

    std::cout << "Top: " << copied_mstack.top() << std::endl;
    std::cout << "Size: " << copied_mstack.size() << std::endl;
    MutantStack<int>::const_reverse_iterator cit = copied_mstack.rbegin();
    MutantStack<int>::const_reverse_iterator cit_end = copied_mstack.rend();

    while (cit != cit_end) {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;
    return 0;

}