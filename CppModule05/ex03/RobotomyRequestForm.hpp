#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &robotomyRequestForm);
        ~RobotomyRequestForm();

        std::string const &getTarget() const;

        void execute(Bureaucrat const &executor) const;
};

#endif