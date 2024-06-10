#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default robotomy request form", 72, 45), _target("default target")
{
    std::cout << this->getName() << ": default robotomy request form constructor called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("robotomy request form", 72, 45), _target(target)
{
    std::cout << this->getName() << ": robotomy request form constructor called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm): AForm(robotomyRequestForm.getName(), robotomyRequestForm.getSignGrade(), robotomyRequestForm.getExecGrade()), _target(robotomyRequestForm.getTarget())
{
    std::cout << this->getName() << ": robotomy request form copy constructor called.\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &robotomyRequestForm)
{
    if (this == &robotomyRequestForm)
        return *this;
    this->_target = robotomyRequestForm.getTarget();
    std::cout << this->getName() << ": robotomy request form assignation operator called.\n";
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << this->getName() << ": robotomy request form destructor called.\n";
}

std::string const &RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    this->checkExecutable(executor);
    std::cout << "Drrrrr...\n";
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully.\n";
    else
        std::cout << this->_target << " robotomization failed.\n";
}


