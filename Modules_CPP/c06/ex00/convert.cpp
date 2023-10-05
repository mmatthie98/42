#include "convert.hpp"

void	only_char(std::string arg)
{
	for (unsigned long i = 1; i < arg.length() ;i++)
	{
		if (arg[i] && (arg[i] >= 97 && arg[i] <= 122))
			continue;
		else
		{
			std::cout << "Error in param" << std::endl;
			break ;
		}
	}
	check_inf(arg);
}

int check_special(std::string arg)
{
	for (unsigned long i = 1; i < arg.length(); i++)
	{
		if (arg[i] && (arg[i] >= 97 && arg[i] <= 122))
			continue;
		else if (arg[i] && (arg[i] >= 48 && arg[i] <= 57))
			continue;
		else if (arg[i] && arg[i] == '.')
			continue;
		else
			std::cout << "Error in param" << std::endl;
	}
	return (check_mod(arg));
}

int check_mod(std::string arg)
{
	int point_flag = 0;
	int f_flag = 0;

	for (unsigned long i = 0; i < arg.length(); i++)
	{
		if (arg[i] && arg[i] == '.' && !point_flag && !f_flag)
		{
			point_flag += 1;
			continue ;
		}
		else if (arg[i] && (arg[i] == 'f') && !f_flag && !point_flag)
		{
			f_flag += 1;
			continue;
		}
		else if (arg[i] && isdigit(arg[i]) && !f_flag)
			continue;
		else if (arg[i] && isalpha(arg[i]) && !point_flag)
			continue;
		else
			std::cout << "Error in param" << std::endl;
	}
	return (0);
}