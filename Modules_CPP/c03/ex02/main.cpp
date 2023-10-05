#include "FragTrap.hpp"

int main()
{
	FragTrap	frag;
	ClapTrap	bob("bob");

	frag.highfive();
	frag.attack("bob");
	bob.takeDamage(1);
	bob.attack("frag");
	frag.takeDamage(1);
	return (0);
}
