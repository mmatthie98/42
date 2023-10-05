#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::map<std::string, float> file_base;
	if (ac != 2)
	{
		std::cerr << "Bad nb of arg" << std::endl;
		return (1);
	}
	else
	{
		try
		{
			BitcoinExchange datalist((std::string(av[1])));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}