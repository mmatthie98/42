#include "FragTrap.hpp"

FragTrap::FragTrap ()
{
	std::cout << "FragTrap default constructor get called" << std::endl;
	hp = 100;
	energy = 100;
	attk = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "Fragtrap destructor get called " << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	name = other.name;
	hp = other.hp;
	energy = other.energy;
	attk = other.attk;
	return (*this);
}

void	FragTrap::highfive(void)
{
	std::cout << "FragTrap " << name << " asked for highfive" << std::endl;
}

