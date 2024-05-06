#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongDog.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongJ = new WrongDog();
    const WrongAnimal* wrongI = new WrongCat();
    

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    animal->makeSound();


    std::cout << wrongJ->getType() << " " << std::endl;
    std::cout << wrongI->getType() << " " << std::endl;
    wrongI->makeSound();
    wrongJ->makeSound();
    wrongAnimal->makeSound();

    delete animal;
    delete j;
    delete i;

    delete wrongAnimal;
    delete wrongJ;
    delete wrongI;
}