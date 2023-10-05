#include "convert.hpp"
int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
		{
			std::cout << "Need more param's" << std::endl;
			return (1);
		}
		check_char(av[1]);
		std::string tmp = av[1];
		if (tmp.length() == 1)
			only_one(tmp);
		else
			multiple_one(tmp);
		check_inf(tmp);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}