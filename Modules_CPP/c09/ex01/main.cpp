#include "RPN.hpp"

int main (int ac, char **av)
{
	try
	{
		if (ac != 2)
		{
			std::cout << "Error need this format : ./RPN <arg>" << std::endl;
			return (1);
		}
		std::string arg(av[1]);
		if (arg.empty())
		{
			std::cout << "Error : use this format | 7 7 + 6 +" << std::endl;
			return (1);		
		}
		RPN rpn(arg);
		rpn.super_calculator(arg);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}