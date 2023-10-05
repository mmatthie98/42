#include "convert.hpp"

void	only_one(std::string tmp)
{
	int i = 0;
	if (std::isdigit(tmp[i]))
	{
		int tst = std::stoi(tmp);
		get_char(tst);
		to_int(tmp);
		to_float(tmp, 1);
		to_double(tmp, 1);
		exit(0);
	}
	else
		print_all(tmp);
}

int check_int(char c)
{
	if (isdigit(c))
		return (1);
	return (0);
}

void	check_char(char	*param)
{
	for (int k = 0; param[k]; k++)
	{
		if (param[k] && (param[k] >= 32 && param[k] <= 127))
			continue ;
		else
			std::cout << "Error in param" << std::endl;
	}
}

void	overflow(void)
{
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : impossible" << std::endl;
	std::cout << "double : impossible" << std::endl;
	exit(-1);
}

void	print_error(int n)
{
	switch (n)
	{
		case (0):
		{
			std::cout << "char : impossible" << std::endl;
			break;
		}
		case (1):
		{
			std::cout << "int : impossible" << std::endl;
			break;
		}
		case (2):
		{
			std::cout << "float : impossible" << std::endl;
			break;
		}
		case (3):
		{
			std::cout << "double: impossible" << std::endl;
			break;
		}
		default:
		{
			overflow();
			break;
		}
	}
}

void	get_char(int data)
{
	if ((data >= 0 && data <= 31) || (data >= 127 && data <= 255))
		std::cout << "char : Non displayable" << std::endl;
	else if (data < 0 || data > 255)
		print_error(0);
	else
		std::cout << "char : '" << static_cast<char>(data) << "'" << std::endl;

}

void int_one(std::string arg)
{
	const char	*tmp = arg.c_str();
	float i = std::atof(tmp);
	if (i > INT_MAX || i < INT_MIN)
		print_error(42);
	else
	{
		get_char(static_cast<int>(i));
		std::cout << "int : " << static_cast<int>(i) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float : " << i << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(i) << std::endl;
		exit(1);
	}
}

void	float_one(std::string arg)
{
	const char	*tmp = arg.c_str();
	double i = std::atof(tmp);
	get_char(static_cast<int>(i));
	if (i < INT_MIN || i > INT_MAX)
		print_error(1);
	else
		to_int(arg);
	if (i > std::numeric_limits<float>::max() || ((i < std::numeric_limits<float>::max() * -1)))
	{
		print_error(2);
		print_error(3);
		exit (0);
	}
	float data = i;
	float test;
	if (std::modf(data, &test))
		std::cout << std::fixed << "float: " << data << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << data << "f" << std::endl;
	double dat;
	if (std::modf(data, &dat))
		std::cout << std::fixed << "double : " << static_cast<double>(i) << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "double : " << static_cast<double>(i) << std::endl;
	exit (EXIT_SUCCESS);
}

void	double_one(std::string tmp)
{
	const char	*arg = tmp.c_str();
	double i = std::atof(arg);
	get_char(static_cast<int>(i));
	if (i < INT_MIN || i > INT_MAX)
		print_error(1);
	else
		to_int(arg);
	if (i > std::numeric_limits<float>::max() || ((i < std::numeric_limits<float>::max() * -1)))
		print_error(2);
	else
	{
		double data;
		if (std::modf(i, &data))
			std::cout << std::fixed << "float: " << static_cast<float>(i) << "f" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << "float :" << static_cast<float>(i) << "f" << std::endl;
	}
	if (i > std::numeric_limits<double>::max() || ((i < std::numeric_limits<double>::max() * -1)))
		std::cout << "double : impossible" << std::endl;
	else
	{
		double tmp2;
		if (std::modf(i, &tmp2))
			std::cout << std::fixed << "double: " << static_cast<double>(i) << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << "double :" << static_cast<double>(i) << std::endl;
	}
	exit(EXIT_SUCCESS);
}

int check(std::string tmp, int special_char, int point_char, int f_char)
{
	if (special_char && point_char)
		double_one(tmp);
	else if (special_char && point_char && f_char)
		float_one(tmp);
	else if (special_char)
		int_one(tmp);
	return (0);
}


int get_the_mod(std::string tmp)
{
	int special_flag = 0;
	int point_flag = 0;
	int f_flag = 0;
	for (unsigned long i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] && (tmp[i] == '-' || tmp[i] == '+') && !special_flag)
		{
			special_flag += 1;
			continue;
		}
		else if (tmp[i] && tmp[i] == '.' && !point_flag)
		{
			point_flag += 1;
			continue;
		}
		else if (tmp[i] && tmp[i] == 'f')
		{
			f_flag += 1;
			continue;
		}
		else
			continue;
	}
	if (f_flag && special_flag)
		std::cout << "Error in params" << std::endl;
	return (check(tmp, special_flag, point_flag, f_flag));
}