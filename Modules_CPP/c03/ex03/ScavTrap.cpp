#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor get called " << std::endl;
	this->hp = 100;
	this->energy = 50;
	this->attk = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor get called " << name << std::endl;
	this->hp = 100;
        this->energy = 50;
        this->attk = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor get called " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap	&other) : ClapTrap(other)
{
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap&	other)
{
	this->name = other.name;
	this->hp = other.hp;
	this->energy = other.energy;
	this->attk = other.attk;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (energy > 0 && hp > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing 20 point of damage" << std::endl;
		energy--;
	}
	else
		std::cout << "not enough energy or hp" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap enter in Gate keeper's mode" << std::endl;
}
