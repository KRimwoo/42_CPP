#include "../includes/Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &animal) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = animal;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &animal)
        this->type = animal.getType();
    return (*this);
}

std::string Animal::getType() const {
    return (this->type);
}

void Animal::makeSound() const {
    std::cout << "Animal doesn't make sound..." << std::endl;
}