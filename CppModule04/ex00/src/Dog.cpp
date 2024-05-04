#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &dog) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = dog;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &dog)
        this->type = dog.getType();
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "Woof!! Woof!!" << std::endl;
}
