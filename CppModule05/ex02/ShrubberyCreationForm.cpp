#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default shrubbery creation form", 145, 137), _target("default target")
{
    std::cout << this->getName() << ": default shrubbery creation form constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("shrubbery creation form", 145, 137), _target(target)
{
    std::cout << this->getName() << ": shrubbery creation form constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm): AForm(shrubberyCreationForm.getName(), shrubberyCreationForm.getSignGrade(), shrubberyCreationForm.getExecGrade()), _target(shrubberyCreationForm.getTarget())
{
    std::cout << this->getName() << ": shrubbery creation form copy constructor called.\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &shrubberyCreationForm)
{
    if (this == &shrubberyCreationForm)
        return *this;
    this->_target = shrubberyCreationForm.getTarget();
    std::cout << this->getName() << ": shrubbery creation form assignation operator called.\n";
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << this->getName() << ": shrubbery creation form destructor called.\n";
}

std::string const &ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    this->checkExecutable(executor);
    std::string filename = this->_target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
        throw FileNotOpenException();
    file << "       ###\n"
            "      #o###\n"
            "    #####o###\n"
            "   #o#\\#|#/###\n"
            "    ###\\|/#o#\n"
            "     # }|{  #\n"
            "       }|{\n";
    file.close();
    if (file.fail())
        throw WriteErrorException();
}

const char *ShrubberyCreationForm::FileNotOpenException::what(void) const throw()
{
    return "File could not be opened.";
}

const char *ShrubberyCreationForm::WriteErrorException::what(void) const throw()
{
    return "Error writing to file.";
}
