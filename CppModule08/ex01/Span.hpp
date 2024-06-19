#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _vector;

public:
    Span();
    Span(unsigned int size);
    Span(Span const &src);
    ~Span();
    Span &operator=(Span const &src);

    void addNumber(int number);
    
    template <typename InputIterator>
    void addNumber(InputIterator begin, InputIterator end)
    {
        for (InputIterator it = begin; it != end; it++)
            addNumber(*it);
    }

    int shortestSpan();
    int longestSpan();
};

#endif