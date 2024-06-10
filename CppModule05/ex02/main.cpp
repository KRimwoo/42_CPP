#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
        Bureaucrat bureaucratA("BureaucratA", 120);
        Bureaucrat bureaucratB("BureaucratB", 60);
        Bureaucrat bureaucratC("BureaucratC", 1);
        
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("woorikim");
        PresidentialPardonForm presidential("robotomized_woorikim");

        std::cout << "=====BureaucratA working=====\n";
        try {
            bureaucratA.signForm(shrubbery);
            bureaucratA.signForm(robotomy);
            
            bureaucratA.executeForm(shrubbery);
            bureaucratA.executeForm(robotomy);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n=====BureaucratB working=====\n";
        try {
            bureaucratB.signForm(shrubbery);
            bureaucratB.signForm(robotomy);
            bureaucratB.signForm(presidential);

            bureaucratB.executeForm(robotomy);
            bureaucratB.executeForm(presidential);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n=====BureaucratC working=====\n";
        try {
            bureaucratC.signForm(presidential);

            bureaucratC.executeForm(robotomy);
            bureaucratC.executeForm(presidential);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	return 0;
}