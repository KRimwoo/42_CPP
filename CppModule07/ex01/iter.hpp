#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int length, void (*func)(T const &))
{
    for (int idx = 0; idx < length; idx++)
        func(array[idx]);
}


template <typename T>
void print(T const &x)
{
    std::cout << x << " ";
}


#endif