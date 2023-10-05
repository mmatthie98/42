#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor get called" << name << std::endl;
	this->name = "Default";
	this->hp = 10;
	this->energy = 10;
	this->attk = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor get called with name" << name << std::endl;
	this->name = name;
	this->hp = 10;
	this->energy = 10;
	this->attk = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor get called " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap	&other)
{
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap&	other)
{
	this->name = other.name;
	this->hp = other.hp;
	this->energy = other.energy;
	this->attk = other.attk;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (energy > 0 && hp > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing 0 point of damage" << std::endl;
		energy--;
	}
	else
		std::cout << "not enough energy or hp" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hp)
		hp -= amount;
	else
		std::cout << name << "is dead " << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hp && energy && hp < 10)
	{
		hp += amount;
		energy -= 1;
		std::cout << name << " got repaired + " << amount << std::endl;
	}
	else if (hp == 10)
		std::cout << name << " is full" << std::endl;
	else if (!energy)
		std::cout << name << " has no more energy bro" << std::endl;
}

int	ClapTrap::check_hp(ClapTrap&	other)
{
	int i = 0;
	if (other.hp)
		return (i = other.hp);
	return (i);
}
