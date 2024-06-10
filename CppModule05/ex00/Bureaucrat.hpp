#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &bureaucrat);
        Bureaucrat &operator=(Bureaucrat const &bureaucrat);
        ~Bureaucrat();

        std::string const &getName() const;
        int const &getGrade() const;

        void increaseGrade(void);
        void decreaseGrade(void);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif