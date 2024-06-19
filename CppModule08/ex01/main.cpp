#include "Span.hpp"
#include <list>

int main()
{
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(5);
        sp.addNumber(1);
        sp.addNumber(2);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        std::cout << "---------------------" << std::endl;
        srand(time(NULL));
        std::vector<int> v;
        for (int i = 0; i < 10001; i++)
            v.push_back(rand());
        Span sp = Span(10000);
        sp.addNumber(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        std::cout << "---------------------" << std::endl;
        std::list<int> l;
        for (int i = 0; i < 30000; i++)
            l.push_back(rand());
        Span sp = Span(30000);
        sp.addNumber(l.begin(), l.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        std::cout << "---------------------" << std::endl;
        Span sp = Span(1);
        sp.addNumber(1);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return 0;
}