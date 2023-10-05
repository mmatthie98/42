#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl harl;
		harl.complain(av[1]);
	}
	else
		std::cout << "please use 1 parameters and for av[1] try : [DEBUG], [INFO], [WARNING]  or [ERROR]" << std::endl;
	return (0);
}