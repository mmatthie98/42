#pragma once

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
	public:
		RPN();
		RPN(std::string arg);
		~RPN();
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
		std::stack<char> st;
		void super_calculator(std::string arg);
		int	get_operator(char c);
};