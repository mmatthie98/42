#include "convert.hpp"

void	Mynan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	inf_low()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void	inf_sup()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

void check_inf(std::string arg)
{
	std::string	tab[6];
	tab[0] = "+inf";
	tab[1] = "+inff";
	tab[2] = "-inf";
	tab[3] = "-inff";
	tab[4] = "nan";
	tab[5] = "nanf";
	int i = 0;
	while (i < 7)
	{
		if (tab[i] == arg)
			break;
		i++;
	}
	switch (i)
	{
		case (0):
		{
			inf_sup();
			break;
		}
		case (1):
		{
			inf_sup();
			break;
		}
		case (2):
		{
			inf_low();
			break;
		}
		case (3):
		{
			inf_low();
			break;
		}
		case (4):
		{
			Mynan();
			break;
		}
		case (5):
		{
			Mynan();
			break;
		}
		default:
			std::cout << "Error in program" << std::endl;
	}
}


void	multiple_one(std::string arg)
{
	if ((arg[0] >= 48 && arg[0] <= 57) || (arg[0] == 45 && (arg[1] >= 48 && arg[1] <= 57)))
	{
		int flag = 0;
		for (int i = 1; arg[i]; i++)
		{
			if (arg[i] == 46 && !flag)
				flag = 1;
			else if ((arg[i] < 48 || arg[i] > 57) || (arg[i] == 46 && flag))
			{
				if ((arg[i] == 'f' || arg[i] == 'F') && !arg[i + 1] && flag)
				{
					flag = 2;
					continue;
				}
				std::cout << "Error in param" << std::endl;
			}
		}
		if (flag == 1)
			double_one(arg);
		else if (flag == 2)
			float_one(arg);
		else
			int_one(arg);
	}
}