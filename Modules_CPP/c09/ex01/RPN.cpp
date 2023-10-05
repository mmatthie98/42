#include "RPN.hpp"

RPN::RPN() {}

bool	token(char arg)
{
	if (arg == '+' || arg == '-' || arg == '*' || arg == '/' || arg == ' ')
		return(true);
	return (false);
}

RPN::RPN(std::string arg)
{
	std::stringstream ss(arg);
	std::string tmp;
	while (std::getline(ss, tmp, ' '))
	{
		if (tmp.size() > 1)
		{
			std::cout << "Error : use number between 0 and 9" << std::endl;
			exit(EXIT_FAILURE);
		}
		else if (!std::isdigit(tmp[0]) && token(tmp[0]) == false)
		{
			std::cout << tmp[0] << " not allowed " << std::endl;
			std::cout << "Error : only use digit or operator [+,-,*,/]" << std::endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			st.push(tmp[0]);
			tmp.clear();
		}
	}
}

RPN::~RPN() {}

RPN::RPN(const RPN	&other)
{
	this->st = other.st;
}

RPN	&RPN::operator=(const RPN	&other)
{
	if (this == &other)
		return (*this);
	this->st = other.st;
	return (*this);
}

int	RPN::get_operator(char c)
{
	if (c == '-')
		return (0);
	else if (c == '+')
		return (1);
	else if (c == '*')
		return (2);
	else
		return (3);
}

void	RPN::super_calculator(std::string arg)
{
	std::stack<int> stack;
	std::stringstream ss(arg);
	std::string tmp;
	while (std::getline(ss, tmp, ' '))
	{
		if (tmp[0] == '-' || tmp[0] == '+' || tmp[0] == '*' || tmp[0] == '/')
		{
			if (stack.size() < 2)
			{
				std::cout << "Error : need at least 2 number to use operation." << std::endl;
				return ;
			}
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			int i = get_operator(tmp[0]);
			switch (i)
			{
				case (0):
				{
					int tmp = b - a;
					stack.push(tmp);
					break;
				}
				case (1):
				{
					int tmp = b + a;
					stack.push(tmp);
					break;
				}
				case (2):
				{
					int tmp = b * a;
					stack.push(tmp);
					break;
				}
				case (3):
				{
					int tmp = b / a;
					stack.push(tmp);
					break;
				}
			}
		}
		else
		{
			int c = std::stoi(tmp);
			stack.push(c);
		}
	}
	if (stack.size() > 1)
	{
		std::cout << "Error : the format is not good" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		int a = stack.top();
		std::cout << a << std::endl;
	}
}
