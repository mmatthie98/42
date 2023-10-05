#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type) {}

void Weapon::set_type(const std::string &new_type)
{
	this->type = new_type;
}

std::string const &Weapon::get_type()
{
	std::string const &weapon = this->type;
	return (weapon);
}
