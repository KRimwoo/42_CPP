#include "Zombie.hpp"

int main(void)
{
	Zombie	zombie1("Zombie1 in stack");
	Zombie	*zombie2 = newZombie("Zombie2 in heap");

	randomChump("Zombie3");
	randomChump("Zombie4");

	zombie1.announce();
	zombie2->announce();

	//delete &zombie1;
	delete zombie2;
	return (0);
}