#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

HumanB::HumanB(std::string name, Weapon &weapon) : name(name), weapon(&weapon) {}

HumanB::~HumanB() {}

void	HumanB::setweapon(Weapon	&weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (!weapon)
		std::cout << this->name << " attack without weapon." << std::endl;
	else
		std::cout << this->name << " attack with their " << this->weapon->get_type() << std::endl;
}
