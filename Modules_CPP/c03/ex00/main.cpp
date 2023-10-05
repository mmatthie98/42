#include "ClapTrap.hpp"

int main()
{
	ClapTrap bob("bob");
	ClapTrap Carlos("Carlos");

	for (int i = 0; i < 9; i++)
		Carlos.attack("bob");
	bob.takeDamage(9);
	Carlos.attack("bob");
	Carlos.beRepaired(1);
	bob.beRepaired(8);
	bob.attack("Carlos");
	return (0);
}
