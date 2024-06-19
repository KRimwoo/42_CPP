#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <vector>


template <typename T, typename F = std::deque<T> >
class MutantStack : public std::stack<T, F>
{
public:
    MutantStack() : std::stack<T, F>() {}
    MutantStack(MutantStack const &src) : std::stack<T, F>(src) {}
    ~MutantStack() {}

    MutantStack &operator=(MutantStack const &src)
    {
        if (this != &src)
            *this = src;
        return *this;
    }


    // iterator
    typedef typename F::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    // const_iterator
    typedef typename F::const_iterator const_iterator;
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    // reverse_iterator
    typedef typename F::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    // const_reverse_iterator
    typedef typename F::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif