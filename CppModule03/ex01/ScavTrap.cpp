#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->name = "default";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap parameter constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap assignation operator called" << std::endl;
    if (this != &scavTrap)
    {
        this->name = scavTrap.getName();
        this->hitPoints = scavTrap.getHitPoints();
        this->energyPoints = scavTrap.getEnergyPoints();
        this->attackDamage = scavTrap.getAttackDamage();
    }
    return (*this);
}

void ScavTrap::attack(const std::string &target)
{
    if (!this->hitPoints)
        std::cout << "ScavTrap " << this->name << " has no hit point." << std::endl;
    else if (!this->energyPoints)
        std::cout << "ScavTrap " << this->name << " does not have enough energy to attack." << std::endl;
    else 
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
}

void ScavTrap::guardGate()
{
    if (!this->hitPoints)
        std::cout << "ScavTrap " << this->name << " has no hit point." << std::endl;
    else if (!this->energyPoints)
        std::cout << "ScavTrap " << this->name << " does not have enough energy to guard." << std::endl;
    else 
        std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode." << std::endl;
}
