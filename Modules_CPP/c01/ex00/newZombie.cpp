#include "Zombie.hpp"

Zombie	*newZombie(std::string	name)
{
	Zombie	*new_one;

	new_one = new Zombie(name);
	new_one->set_name(name);
	return (new_one);
}
