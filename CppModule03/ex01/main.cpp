#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a("A");
    ClapTrap b("B");

    a.attack("B");
    b.takeDamage(3);
    std::cout << "a's hit points: " << a.getHitPoints() << std::endl;
    std::cout << "a's energy points: " << a.getEnergyPoints() << std::endl;
    std::cout << "a's attack damage: " << a.getAttackDamage() << std::endl;
    std::cout << "b's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "b's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "b's attack damage: " << b.getAttackDamage() << std::endl;
    b.beRepaired(2);
    
    ScavTrap c = a;
    std::cout << "c's hit points: " << c.getHitPoints() << std::endl;
    std::cout << "c's energy points: " << c.getEnergyPoints() << std::endl;
    std::cout << "c's attack damage: " << c.getAttackDamage() << std::endl;
    c.attack("B");
    b.takeDamage(5);
    b.attack("A");
    c.takeDamage(10);
    std::cout << "c's hit points: " << c.getHitPoints() << std::endl;
    std::cout << "c's energy points: " << c.getEnergyPoints() << std::endl;
    std::cout << "c's attack damage: " << c.getAttackDamage() << std::endl;
    std::cout << "b's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "b's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "b's attack damage: " << b.getAttackDamage() << std::endl;

    c.guardGate();
    // std::cout << "-------------------" << std::endl;
    // ScavTrap *d = new ScavTrap();
    // delete d;
    // std::cout << "-------------------" << std::endl;
}