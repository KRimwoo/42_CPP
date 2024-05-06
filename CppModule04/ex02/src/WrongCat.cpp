#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = wrongCat;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
    std::cout << "WrongCat assignation operator called" << std::endl;
    if (this != &wrongCat)
        this->type = wrongCat.getType();
    return (*this);
}

void WrongCat::makeSound() const {
    std::cout << "moeW..." << std::endl;
}

