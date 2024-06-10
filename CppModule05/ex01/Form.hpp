#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _isSigned;
		int const _signGrade;
		int const _execGrade;
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const &form);
		Form &operator=(Form const &aform);
		~Form();

		std::string const &getName() const;
		bool const &getIsSigned() const;
        int const &getSignGrade() const;
        int const &getExecGrade() const;

        void beSigned(Bureaucrat const &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, const Form &form);


#endif