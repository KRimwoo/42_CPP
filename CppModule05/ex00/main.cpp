#include "Bureaucrat.hpp"

int main()
{
    try {
        try {
            Bureaucrat a("A", 200);
        }
        catch (const std::exception &e) {
            std::cerr << e.what();
        }
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