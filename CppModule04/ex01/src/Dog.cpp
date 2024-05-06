#include "../includes/Dog.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain("dog idea");
}

Dog::Dog(const Dog &dog) : Animal(dog) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = dog;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &dog)
        this->type = dog.getType();
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*(dog.brain));
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "Woof!! Woof!!" << std::endl;
}

std::string Dog::getDogIdea(int index) {
    return (brain->getIdea(index));
}

void Dog::setDogIdea(int index, std::string idea) {
    brain->setIdea(index, idea);
}
