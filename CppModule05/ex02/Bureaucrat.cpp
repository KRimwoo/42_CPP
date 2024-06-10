#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default bureaucrat"), _grade(150) 
{
    std::cout << this->_name << ": default bureaucrat constructor called.\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
    std::cout << this->_name << ": bureaucrat constructor called.\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : _name(bureaucrat.getName())
{
    this->_grade = bureaucrat.getGrade();
    std::cout << this->_name << ": bureaucrat copy constructor called.\n";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
    if (this == &bureaucrat)
        return *this;
    this->_grade = bureaucrat.getGrade();
    std::cout << this->_name << ": bureaucrat assignation operator called.\n";
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << this->_name << ": bureaucrat destructor called.\n";
}

std::string const &Bureaucrat::getName() const
{
    return this->_name;
}

int const &Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::increaseGrade(void)
{
    if (this->_grade <= 1)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decreaseGrade(void)
{
    if (this->_grade >= 150)
        throw GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << ".\n";
    }
    catch (bool sign) {
        std::cout << this->_name << " cannot sign " << form.getName() << " because it is already signed.\n";
    }
    catch (std::exception &e) {
        std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what();
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try {
        form.execute(*this);
        std::cout << this->_name << " executes " << form.getName() << ".\n";
    }
    catch (std::exception &e) {
        std::cout << this->_name << " cannot execute " << form.getName() << " because " << e.what();
    }
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "Grade is too high!\n";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "Grade is too low!\n";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << "'s grade is "  << bureaucrat.getGrade() << ".\n";
    return out;
}

