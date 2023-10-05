#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(const	std::string	&type);
		const	std::string &get_type();
		void 	set_type(const std::string &new_type);
};






#endif
