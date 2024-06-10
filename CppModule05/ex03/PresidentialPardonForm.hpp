#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &presidentialPardonForm);
        ~PresidentialPardonForm();

        std::string const &getTarget() const;

        void execute(Bureaucrat const &executor) const;
};

#endif