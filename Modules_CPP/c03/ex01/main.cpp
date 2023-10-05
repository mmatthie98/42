#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Carlos");
	ScavTrap scav("bob");
	clap.attack("bob");
	scav.attack("Carlos");
	clap.takeDamage(1);
	scav.guardGate();
	return (0);
}
