#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default presidential pardon form", 25, 5), _target("default target")
{
    std::cout << this->getName() << ": default presidential pardon form constructor called.\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("presidential pardon form", 25, 5), _target(target)
{
    std::cout << this->getName() << ": presidential pardon form constructor called.\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm): AForm(presidentialPardonForm.getName(), presidentialPardonForm.getSignGrade(), presidentialPardonForm.getExecGrade()), _target(presidentialPardonForm.getTarget())
{
    std::cout << this->getName() << ": presidential pardon form copy constructor called.\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &presidentialPardonForm)
{
    if (this == &presidentialPardonForm)
        return *this;
    this->_target = presidentialPardonForm.getTarget();
    std::cout << this->getName() << ": presidential pardon form assignation operator called.\n";
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << this->getName() << ": presidential pardon form destructor called.\n";
}

std::string const &PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    this->checkExecutable(executor);
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox.\n";
}

