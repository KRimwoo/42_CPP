#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    Bureaucrat bureaucratA("BureaucratA", 10);
    Bureaucrat bureaucratB("BureaucratB", 1);

    try {
        std::cout << "=====Shrubbery Form Creation=====\n";
        AForm *scf = intern.makeForm("shrubbery creation", "home");

        if (scf) {
            std::cout << *scf;
            delete scf;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=====Robotomy Form Creation=====\n";
        AForm *rrf = intern.makeForm("robotomy request", "road");

        if (rrf) {
            std::cout << *rrf;
            delete rrf;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=====Presidential Form Creation=====\n";
        AForm *ppf = intern.makeForm("presidential pardon", "president");

        if (ppf) {
            std::cout << *ppf;

            std::cout << "\n=====Bureaucrats working=====\n";
            bureaucratA.signForm(*ppf);
            bureaucratB.executeForm(*ppf);
            delete ppf;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=====Unknown Form Creation=====\n";
        AForm *unknown = intern.makeForm("unknown", "unknown");

        if (unknown) {
            std::cout << *unknown;
            std::cout << "\n=====BureaucratA working=====\n";
            bureaucratA.signForm(*unknown);
            delete unknown;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}