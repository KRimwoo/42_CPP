#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
    T *_array;
    unsigned int _size;

public:
    Array() : _array(NULL), _size(0) {}
    Array(unsigned int n) : _array(new T[n]()), _size(n) {}
    Array(Array const &src) : _array(new T[src._size]()), _size(src._size)
    {
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = src._array[i];
    }
    ~Array() {
        delete[] _array; 
    }

    Array &operator=(Array const &src)
    {
        if (this != &src)
        {
            delete[] _array;
            _array = new T[src._size]();
            _size = src._size;
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = src._array[i];
        }
        return *this;
    }

    T &operator[](unsigned int idx)
    {
        if (idx >= _size)
            throw std::out_of_range("Index out of range");
        return _array[idx];
    }

    T const &operator[](unsigned int idx) const
    {
        if (idx >= _size)
            throw std::out_of_range("Index out of range");
        return _array[idx];
    }

    unsigned int size() const { return _size; }
};

#endif