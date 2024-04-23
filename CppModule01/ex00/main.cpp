#include "Zombie.hpp"

int main(void)
{
	Zombie	zombie1("Zombie1 in stack");
	Zombie	*zombie2 = newZombie("Zombie2 in heap");

	randomChump("Zombie3 in stack");
	randomChump("Zombie4 in stack");

	zombie1.announce();
	zombie2->announce();

	delete zombie2;
	return (0);
}