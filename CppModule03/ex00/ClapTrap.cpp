#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    this->name = "default";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap parameter constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &clapTrap)
    {
        this->name = clapTrap.getName();
        this->hitPoints = clapTrap.getHitPoints();
        this->energyPoints = clapTrap.getEnergyPoints();
        this->attackDamage = clapTrap.getAttackDamage();
    }
    return (*this);
}

std::string ClapTrap::getName() const
{
    return (this->name);
}

int ClapTrap::getHitPoints() const
{
    return (this->hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
    return (this->energyPoints);
}

int ClapTrap::getAttackDamage() const
{
    return (this->attackDamage);
}

void ClapTrap::attack(const std::string &target)
{
    if (!this->hitPoints)
    {
        std::cout << "ClapTrap " << this->name << " has no hit point." << std::endl;
        return ;
    }
    else if (!this->energyPoints)
    {
        std::cout << "ClapTrap " << this->name << " does not have enough energy to attack." << std::endl;
        return ;
    }
    else 
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!this->hitPoints)
        std::cout << "ClapTrap " << this->name << " has no hit point." << std::endl;
    else
    {
        if (this->hitPoints < amount)
            this->hitPoints = 0;
        else
            this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " has taken " << amount << " points of damage!" << std::endl;
        // std::cout << "Now, ";
        // if (!this->hitPoints)
        //     std::cout << "ClapTrap " << this->name << " has no hit point." << std::endl;
        // else 
        //     std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " hit points left." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->energyPoints)
        std::cout << "ClapTrap " << this->name << " has no energy point." << std::endl;
    else if (!this->hitPoints)
        std::cout << "ClapTrap " << this->name << " has no hit point." << std::endl;
    else
    {
        this->hitPoints += amount;
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " has been repaired by " << amount << " points!" << std::endl;
        // std::cout << "Now, ClapTrap " << this->name << " has " << this->hitPoints << " hit points." << std::endl;
    }
}