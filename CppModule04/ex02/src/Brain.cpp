#include "../includes/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::stringstream ss;
        ss << "idea" << i;
        this->ideas[i] = ss.str();
    }
}

Brain::Brain(std::string idea)
{
    std::cout << "Brain parameter constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::stringstream ss;
        ss << idea << i;
        this->ideas[i] = ss.str();
    }
}

Brain::Brain(const Brain &brain)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = brain;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = brain.getIdea(i);
    }
    return (*this);
}

std::string Brain::getIdea(int i) const
{
    if (i < 0 || i >= 100)
    {
        std::cout << "Index out of range" << std::endl;
        return ("");
    }
    return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
    if (i < 0 || i >= 100)
    {
        std::cout << "Index out of range" << std::endl;
        return;
    }
    this->ideas[i] = idea;
}