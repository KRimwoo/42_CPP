#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &shrubberyCreationForm);
        ~ShrubberyCreationForm();

        std::string const &getTarget() const;

        void execute(Bureaucrat const &executor) const;

        class FileNotOpenException : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };

        class WriteErrorException : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
};

#endif