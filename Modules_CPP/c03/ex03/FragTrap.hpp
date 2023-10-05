#pragma once

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(const FragTrap	&other);
		void	highfive(void);
		FragTrap&	operator=(const	FragTrap	&other);
};
