#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap a("A");
    ScavTrap b("B");
    FragTrap c("C");
    ClapTrap d(b);

    a.attack("B");
    b.takeDamage(3);
    std::cout << "a's hit points: " << a.getHitPoints() << std::endl;
    std::cout << "a's energy points: " << a.getEnergyPoints() << std::endl;
    std::cout << "a's attack damage: " << a.getAttackDamage() << std::endl;
    std::cout << "b's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "b's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "b's attack damage: " << b.getAttackDamage() << std::endl;
    
    b.beRepaired(2);
    b.attack("C");
    c.takeDamage(20);
    c.attack("B");
    b.takeDamage(30);
    std::cout << "c's hit points: " << c.getHitPoints() << std::endl;
    std::cout << "c's energy points: " << c.getEnergyPoints() << std::endl;
    std::cout << "c's attack damage: " << c.getAttackDamage() << std::endl;
    std::cout << "b's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "b's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "b's attack damage: " << b.getAttackDamage() << std::endl;
    b.guardGate();
    c.highFivesGuys();
}