#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("A");
    ClapTrap b("B");

    a.attack("B");
    std::cout << "a's hit points: " << a.getHitPoints() << std::endl;
    std::cout << "a's energy points: " << a.getEnergyPoints() << std::endl;
    std::cout << "a's attack damage: " << a.getAttackDamage() << std::endl;

    b.takeDamage(5);
    std::cout << "b's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "b's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "b's attack damage: " << b.getAttackDamage() << std::endl;

    b.beRepaired(5);
    std::cout << "b's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "b's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "b's attack damage: " << b.getAttackDamage() << std::endl;

    b.attack("A");
    a.takeDamage(10);
    std::cout << "b's hit points: " << b.getHitPoints() << std::endl;
    std::cout << "b's energy points: " << b.getEnergyPoints() << std::endl;
    std::cout << "b's attack damage: " << b.getAttackDamage() << std::endl;
    std::cout << "a's hit points: " << a.getHitPoints() << std::endl;
    std::cout << "a's energy points: " << a.getEnergyPoints() << std::endl;
    std::cout << "a's attack damage: " << a.getAttackDamage() << std::endl;
    a.beRepaired(10);
    std::cout << "a's hit points: " << a.getHitPoints() << std::endl;
    std::cout << "a's energy points: " << a.getEnergyPoints() << std::endl;
    std::cout << "a's attack damage: " << a.getAttackDamage() << std::endl;


    ClapTrap c = a;
    std::cout << "c's hit points: " << c.getHitPoints() << std::endl;
    std::cout << "c's energy points: " << c.getEnergyPoints() << std::endl;
    std::cout << "c's attack damage: " << c.getAttackDamage() << std::endl;
    ClapTrap d(b);
    std::cout << "d's hit points: " << d.getHitPoints() << std::endl;
    std::cout << "d's energy points: " << d.getEnergyPoints() << std::endl;
    std::cout << "d's attack damage: " << d.getAttackDamage() << std::endl;
}