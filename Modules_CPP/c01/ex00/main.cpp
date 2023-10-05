#include "Zombie.hpp"

int main()
{
	std::string name, second;

	name = "Bob";
	second = "Marley";
	Zombie* z = newZombie(name);
  	z->announce();
	randomChump(second);
  	delete z;
	return (0);
}
