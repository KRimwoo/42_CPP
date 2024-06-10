#include "Bureaucrat.hpp"

int main()
{
    try {
        std::cout << "=====Creating a BureaucratA=====" << std::endl;
        Bureaucrat a("A", 200);
        std::cout << a;
    }
    catch (const std::exception &e) {
        std::cerr << e.what();
    }

    try {
        std::cout << "\n=====Creating a BureaucratB, C, D, E=====" << std::endl;
        Bureaucrat b("B", 150);
        Bureaucrat c = b;
        Bureaucrat d;
        Bureaucrat e("E", 1);

        std::cout << b;
        std::cout << c;
        std::cout << d;
        std::cout << e;
        
        b.decreaseGrade();
        e.increaseGrade();
    }
    catch (const std::exception &e) {
        std::cerr << e.what();
    }
}