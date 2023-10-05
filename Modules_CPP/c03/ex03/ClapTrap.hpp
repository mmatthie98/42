#pragma once

#include <iostream>

class ClapTrap
{
	protected:
		std::string	name;
		int	hp;
		int	energy;
		int	attk;
	public:
		ClapTrap();
		ClapTrap(std::string str);
		ClapTrap(const	ClapTrap		&other);
		~ClapTrap();
		ClapTrap&	operator=(const	ClapTrap	&other);
		void	attack(const	std::string	&target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		int	check_hp(ClapTrap&	other);
};
