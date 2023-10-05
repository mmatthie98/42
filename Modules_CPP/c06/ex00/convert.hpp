#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cmath>
//void	special_char(std::string tmp);
void 	int_one(std::string arg);
void	only_one(std::string tmp);
void 	check_char(char	*param);
void	print_error(int n);
void 	to_float(std::string arg, int i);
void 	to_int(std::string arg);
void 	print_all(std::string arg);
void 	to_double(std::string arg, int i);
void	multiple_one(std::string arg);
void	only_char(std::string arg);
int 	check_special(std::string arg);
void	special_char(std::string tmp);
void	check_inf(std::string arg);
int 	check_mod(std::string arg);
void	double_one(std::string tmp);
void	float_one(std::string tmp);
void	int_or_char(std::string tmp);
void	get_char(int data);

#endif