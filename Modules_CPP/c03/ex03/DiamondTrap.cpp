#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name")
{
	std::cout << "DiamondTrap default constructor get called" << std::endl;
	this->name = "default";
	this->attk = FragTrap::attk;
	this->energy = ScavTrap::energy;
	this->hp = FragTrap::hp;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor get called with name" << name << std::endl;
	this->name = name;
	this->attk = FragTrap::attk;
	this->energy = ScavTrap::energy;
	this->hp = FragTrap::hp;
}

DiamondTrap::DiamondTrap(const	DiamondTrap	&other)
{
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor get called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	this->name = other.name;
	this->hp = other.hp;
	this->energy = other.energy;
	this->attk = other.attk;
	return (*this);
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoami()
{
	std::cout << "The Diamond name is = " << this->name << std::endl;
	std::cout << "The ClapTrap name = " << ClapTrap::name << std::endl;
}
