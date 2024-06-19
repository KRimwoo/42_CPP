#include "Span.hpp"

Span::Span(): _maxSize(0) {}

Span::Span(unsigned int size): _maxSize(size) {}

Span::Span(Span const &src): _maxSize(src._maxSize), _vector(src._vector) {}

Span::~Span() {}

Span &Span::operator=(Span const &src)
{
    if (this != &src)
    {
        _maxSize = src._maxSize;
        _vector = src._vector;
    }
    return *this;
}

void Span::addNumber(int number)
{
    try {
        if (_vector.size() >= this->_maxSize)
            throw std::out_of_range("Span is full");
        _vector.push_back(number);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int Span::shortestSpan()
{
    int shortestSpan = 2147483647;
    try {
        if (_vector.size() <= 1)
            throw std::out_of_range("Span is empty or has only one element");
        std::vector<int> sortedVector = _vector;
        std::sort(sortedVector.begin(), sortedVector.end());
        shortestSpan = sortedVector[1] - sortedVector[0];
        for (unsigned int i = 1; i < sortedVector.size(); i++)
        {
            int span = sortedVector[i] - sortedVector[i - 1];
            if (span < shortestSpan)
                shortestSpan = span;
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return shortestSpan;
}

int Span::longestSpan()
{
    std::vector<int> sortedVector = _vector;
    try {
        if (_vector.size() <= 1)
            throw std::out_of_range("Span is empty or has only one element");
        std::sort(sortedVector.begin(), sortedVector.end());
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return sortedVector[sortedVector.size() - 1] - sortedVector[0];
}

