#include <iostream>
#include "convert.hpp"

void print_all(std::string arg)
{
	int i = arg[0];
	std::cout << "Char : '" << arg << "'" << std::endl;
	std::cout << "Int : " << i << std::endl;
	to_float(arg, 0);
	to_double(arg, 0);
	exit(0);
}

void to_float(std::string arg, int mod)
{
	if (mod == 1)
	{
		int i = std::stoi(arg);
		std::cout << "Float : " << i << ".0f" << std::endl;
	}
	else if (mod == 2)
	{
		int i = std::stof(arg);
		std::cout << std::fixed << std::setprecision(1) << "Float : " << i << ".0f" << std::endl;
	}
	else
	{
		int i = arg[0];
		std::cout << "Float : " << i << ".0f" << std::endl;
	}
}	

void to_double(std::string arg, int mod)
{
	if (mod == 1)
	{
		int i = std::stoi(arg);
		std::cout << "Double : " << i << ".0" << std::endl;
	}
	else if (mod == 2)
	{
		int i = std::stof(arg);
		std::cout << "Double : " << i << ".0" << std::endl;
	}
	else
	{
		int i = arg[0];
		std::cout << "Double : " << i << ".0" << std::endl;
	}
}

void to_int(std::string arg)
{
	int i = std::stoi(arg);
	std::cout << "Int : " << i << std::endl;
}