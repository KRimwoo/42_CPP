#include "../includes/Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain("cat idea");
}

Cat::Cat(const Cat &cat) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = cat;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &cat)
        this->type = cat.getType();
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*(cat.brain));
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meow..." << std::endl;
}

std::string Cat::getCatIdea(int index) {
    return (brain->getIdea(index));
}

void Cat::setCatIdea(int index, std::string idea) {
    brain->setIdea(index, idea);
}
