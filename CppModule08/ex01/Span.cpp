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
    if (_vector.size() >= _maxSize)
        throw std::out_of_range("Span is full");
    _vector.push_back(number);
}

int Span::shortestSpan()
{
    if (_vector.size() <= 1)
        throw std::out_of_range("Span is empty or has only one element");
    std::vector<int> sortedVector = _vector;
    std::sort(sortedVector.begin(), sortedVector.end());
    int shortestSpan = sortedVector[1] - sortedVector[0];
    for (unsigned int i = 1; i < sortedVector.size(); i++)
    {
        int span = sortedVector[i] - sortedVector[i - 1];
        if (span < shortestSpan)
            shortestSpan = span;
    }
    return shortestSpan;
}

int Span::longestSpan()
{
    if (_vector.size() <= 1)
        throw std::out_of_range("Span is empty or has only one element");
    std::vector<int> sortedVector = _vector;
    std::sort(sortedVector.begin(), sortedVector.end());
    return sortedVector[sortedVector.size() - 1] - sortedVector[0];
}

