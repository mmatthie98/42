#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);
		~HumanB();
		void attack();
		void	setweapon(Weapon	&weapon);
	private:
		std::string name;
		Weapon *weapon;
};


#endif
