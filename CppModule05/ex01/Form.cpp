#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
	std::cout << this->_name << ": default form constructor called.\n";
}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
	std::cout << this->_name << " : form constructor called.\n";
}

Form::Form(Form const &form) : _name(form.getName()), _isSigned(form.getIsSigned()), _signGrade(form.getSignGrade()), _execGrade(form.getExecGrade())
{
	std::cout << this->_name << " : form copy constructor called.\n";
}

Form &Form::operator=(Form const &form)
{
	if (this == &form)
		return *this;
	this->_isSigned = form.getIsSigned();
	std::cout << this->_name << " : form assignation operator called.\n";
	return *this;
}

Form::~Form()
{
	std::cout << this->_name << " : form destructor called.\n";
}

std::string const &Form::getName() const
{
	return this->_name;
}

bool const &Form::getIsSigned() const
{
	return this->_isSigned;
}

int const &Form::getSignGrade() const
{
	return this->_signGrade;
}

int const &Form::getExecGrade() const
{
	return this->_execGrade;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	else if (_isSigned)
		throw _isSigned;
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high.\n";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low.\n";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() << std::boolalpha << ", is signed: "
		<< form.getIsSigned() << ", sign grade: " << form.getSignGrade()
		<< ", exec grade: " << form.getExecGrade() << std::endl;
	return out;
}

