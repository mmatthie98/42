#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(const FragTrap	&other);
		void	highfive(void);
		FragTrap&	operator=(const	FragTrap	&other);
};
#endif
