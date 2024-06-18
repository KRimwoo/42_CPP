#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T, typename F = >
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(MutantStack const &src) : std::stack<T>(src) {}
    ~MutantStack() {}

    MutantStack &operator=(MutantStack const &src)
    {
        if (this != &src)
            std::stack<T>::operator=(src);
        return *this;
    }


    /* iterator */
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    /* const_iterator */
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    /* reverse_iterator */
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() { return this->c.rbegin(); }
};

#endif