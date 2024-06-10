#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
	std::cout << this->_name << ": default aForm constructor called.\n";
}

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
	std::cout << this->_name << " : aForm constructor called.\n";
}

AForm::AForm(AForm const &aForm) : _name(aForm.getName()), _isSigned(aForm.getIsSigned()), _signGrade(aForm.getSignGrade()), _execGrade(aForm.getExecGrade())
{
	std::cout << this->_name << " : aForm copy constructor called.\n";
}

AForm &AForm::operator=(AForm const &aForm)
{
	if (this == &aForm)
		return *this;
	this->_isSigned = aForm.getIsSigned();
	std::cout << this->_name << " : aForm assignation operator called.\n";
	return *this;
}

AForm::~AForm()
{
	std::cout << this->_name << " : aForm destructor called.\n";
}

std::string const &AForm::getName() const
{
	return this->_name;
}

bool const &AForm::getIsSigned() const
{
	return this->_isSigned;
}

int const &AForm::getSignGrade() const
{
	return this->_signGrade;
}

int const &AForm::getExecGrade() const
{
	return this->_execGrade;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	else if (_isSigned)
		throw _isSigned;
	this->_isSigned = true;
}

void AForm::checkExecutable(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->_execGrade)
		throw GradeTooLowToExecuteException();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high.\n";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low.\n";
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return "Form is not signed.\n";
}

const char *AForm::GradeTooLowToExecuteException::what(void) const throw()
{
	return "Grade is too low to execute.\n";
}

std::ostream &operator<<(std::ostream &out, const AForm &aForm)
{
	out << "AForm: " << aForm.getName() << std::boolalpha << ", is signed: "
		<< aForm.getIsSigned() << ", sign grade: " << aForm.getSignGrade()
		<< ", exec grade: " << aForm.getExecGrade() << std::endl;
	return out;
}

