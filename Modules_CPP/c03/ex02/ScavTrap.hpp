#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string str);
		ScavTrap(const	ScavTrap	&other);
		~ScavTrap();
		ScavTrap&	operator=(const	ScavTrap	&other);
		int	check_hp(ScavTrap&	other);
		void	attack(const	std::string	&target);
		void	guardGate(void);
};




#endif
