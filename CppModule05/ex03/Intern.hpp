#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        Intern(Intern const &intern);
        Intern &operator=(Intern const &intern);
        ~Intern();

        AForm *makeForm(std::string const &formName, std::string const &target);

        AForm *makeShrubberyCreationForm(std::string const &target);
        AForm *makeRobotomyRequestForm(std::string const &target);
        AForm *makePresidentialPardonForm(std::string const &target);

        class InvalidFormNameException : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
};

#endif