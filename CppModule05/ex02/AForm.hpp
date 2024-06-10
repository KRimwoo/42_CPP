#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _isSigned;
		int const _signGrade;
		int const _execGrade;
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm const &aForm);
		AForm &operator=(AForm const &aForm);
		virtual ~AForm();

		std::string const &getName() const;
		bool const &getIsSigned() const;
        int const &getSignGrade() const;
        int const &getExecGrade() const;

        void beSigned(Bureaucrat const &bureaucrat);

        virtual void execute(Bureaucrat const &executor) const = 0;
        void checkExecutable(Bureaucrat const &executor) const;

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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };

        class GradeTooLowToExecuteException : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &aForm);


#endif