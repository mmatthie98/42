#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string str);
		ScavTrap(const	ScavTrap	&other);
		~ScavTrap();
		ScavTrap&	operator=(const	ScavTrap	&other);
		void	attack(const	std::string	&target);
		void	guardGate(void);
};
