#include "../includes/WrongDog.hpp"

WrongDog::WrongDog() {
    std::cout << "WrongDog default constructor called" << std::endl;
    this->type = "WrongDog";
}

WrongDog::WrongDog(const WrongDog &wrongDog) {
    std::cout << "WrongDog copy constructor called" << std::endl;
    *this = wrongDog;
}

WrongDog::~WrongDog() {
    std::cout << "WrongDog destructor called" << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &wrongDog) {
    std::cout << "WrongDog assignation operator called" << std::endl;
    if (this != &wrongDog)
        this->type = wrongDog.getType();
    return (*this);
}

void WrongDog::makeSound() const {
    std::cout << "!!jooM !!jooM" << std::endl;
}
