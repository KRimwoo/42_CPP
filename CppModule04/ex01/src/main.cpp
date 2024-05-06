#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongDog.hpp"

int main()
{
    std::cout << \
        "=============Animal tests=============" << std::endl << std::endl;
    const Animal *animals[4];

    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << std::endl;

    for (int i = 0; i < 4; i++)
    {
        animals[i]->makeSound();
        delete animals[i];
    }

    std::cout << std::endl << \
        "=============Wrong Animal tests=============" << std::endl << std::endl;
    const WrongAnimal *wrongAnimals[4];
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
            wrongAnimals[i] = new WrongDog();
        else
            wrongAnimals[i] = new WrongCat();
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        wrongAnimals[i]->makeSound();
        delete wrongAnimals[i];
    }
    WrongCat wrongCat;
    wrongCat.makeSound();

    std::cout << std::endl << \
        "=============Dog copy tests=============" << std::endl << std::endl;

    Dog *dog = new Dog();
    std::cout << "Dog's first idea: " << dog->getDogIdea(0) << std::endl;
    std::cout << "Dog's second idea: " << dog->getDogIdea(1) << std::endl;
    std::cout << "Dog's 99th idea: " << dog->getDogIdea(99) << std::endl;
    std::cout << "Dog's 100th idea: " << dog->getDogIdea(100) << std::endl;
    Dog *copyDog = new Dog();
    *copyDog = *dog;

    dog->setDogIdea(99, "dog's 99th new idea!!");
    std::cout << "Dog's 99th idea: " << dog->getDogIdea(99) << std::endl;
    std::cout << "Copy Dog's 99th idea: " << copyDog->getDogIdea(99) << std::endl;

    dog->setDogIdea(100, "dog's 100th new idea!!");

    delete dog;
    delete copyDog;

    std::cout << std::endl << \
        "=============Cat copy tests=============" << std::endl << std::endl;
    Cat cat = Cat();
    std::cout << "Cat's first idea: " << cat.getCatIdea(0) << std::endl;
    std::cout << "Cat's second idea: " << cat.getCatIdea(1) << std::endl;
    std::cout << "Cat's 99th idea: " << cat.getCatIdea(99) << std::endl;
    std::cout << "Cat's 100th idea: " << cat.getCatIdea(100) << std::endl;

    Cat copyCat = Cat(cat);
    cat.setCatIdea(99, "cat's 99th new idea!!");
    std::cout << "Cat's 99th idea: " << cat.getCatIdea(99) << std::endl;
    std::cout << "Copy Cat's 99th idea: " << copyCat.getCatIdea(99) << std::endl;


    std::cout << std::endl << \
        "=============Program ends=============" << std::endl << std::endl;
    return 0;
}