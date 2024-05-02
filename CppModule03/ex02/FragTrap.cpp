#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->name = "default";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap parameter constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = fragTrap;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}


FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    if (this != &fragTrap)
    {
        this->name = fragTrap.getName();
        this->hitPoints = fragTrap.getHitPoints();
        this->energyPoints = fragTrap.getEnergyPoints();
        this->attackDamage = fragTrap.getAttackDamage();
    }
    return (*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->name << " is asking for a high five!" << std::endl;
}