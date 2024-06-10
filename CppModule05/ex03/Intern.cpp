#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called.\n";
}

Intern::Intern(Intern const &intern)
{
    std::cout << "Intern copy constructor called.\n";
    *this = intern;
}

Intern &Intern::operator=(Intern const &intern)
{
    std::cout << "Intern assignation operator called.\n";
    (void)intern;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called.\n";
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
    try {
        const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
        AForm *(Intern::*formList[3])(const std::string &) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

        AForm *res = NULL;
        for (int i = 0; i < 3; i++)
        {
            if (formName == formNames[i]) {
                res = (this->*formList[i])(target);
                std::cout << "Intern creates " << formName << " form.\n";
                return res;
            }
        }
        throw InvalidFormNameException();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return NULL;
    }
}

AForm *Intern::makeShrubberyCreationForm(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string const &target)
{
    return new PresidentialPardonForm(target);
}

const char *Intern::InvalidFormNameException::what(void) const throw()
{
    return "Form name is invalid.";
}