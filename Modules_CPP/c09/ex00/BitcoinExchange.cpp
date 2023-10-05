#include "BitcoinExchange.hpp"

void	BitcoinExchange::parse_file()
{
	std::ifstream datafile("data.csv");
	if (!datafile)
	{
		std::cerr << "Error : could not found data.csv." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string name;
	if (std::getline(datafile, name, '\n'))
	{
		std::getline(datafile, name, '\n');
		while (!name.empty())
		{
			std::string key = name.substr(0, name.find(','));
			std::string str = name.substr(name.find(',') + 1);
			float value = std::stof(str);
			reference_database[key] = value;
			std::getline(datafile,name,'\n');
		}
	}
	else
	{
		std::cerr << "Error : data.csv is empty." << std::endl;
		exit(EXIT_FAILURE);
	}
	datafile.close();
}

BitcoinExchange::BitcoinExchange(std::string arg)
{
	parse_file();
	open_it(arg);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->reference_database = other.reference_database;
	this->database = other.database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	this->reference_database = other.reference_database;
	this->database = other.database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::open_it(std::string arg)
{
	std::ifstream file(arg);
	std::string	tmp;
	if (!file)
	{
		std::cerr << "Error : could not open file." << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		if (std::getline(file, tmp, '\n'))
		{
			while (!tmp.empty())
			{
				parse_it(tmp);
				tmp.clear();
				std::getline(file, tmp, '\n');
			}
		}
	}
	file.close();
	return ;
}

void	BitcoinExchange::parse_it(std::string data)
{
	try
	{
		std::string date;
		std::string amount;
		int flag = 0;
		if (data.find('|') != std::string::npos)
		{
			char test = data.at(data.find('|') - 1);
			char test2 = data.at(data.find('|') + 1);
			if (test != ' ' || test2 != ' ')
				flag = 1;
			date = data.substr(0 ,data.find('|') - 1);
			amount = data.substr(data.find('|') + 2);
			switch (check_all(date, amount, flag))
			{
				case (0):
				{
					std::cout << date << " => " << amount << " = " << rate(amount, date) << std::endl;
					break;
				}
				case (1):
				{
					std::cout << "Error : bad input => " << date << std::endl;
					break;
				}
				case (2):
				{
					throw NotPositiveNumber();
					break;
				}
				case (3):
				{
					throw TooLargeNumber();
					break;
				}
				case (4):
				{
					throw BadInput();
					break;
				}
			}
		}
		else
			std::cout << "Error : bad input => " << data << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int BitcoinExchange::check_all(std::string date, std::string amount, int flag)
{
	if (flag != 0)
		return (4);
	unsigned int i = 0;
	if (date.size() != 10 || (date.at(4) != '-' || date.at(7) != '-'))
		return (1);
	std::string  tab[3];
	tab[0] = date.substr(0, 4);
	tab[1] = date.substr(5, 2);
	tab[2] = date.substr(8, 2);
	while (i < tab->size() - 1)
	{
		if (check_date(tab[i]))
			return (1);
		i++;
	}
	if (check_amount(amount) != 0)
		return (check_amount(amount));
	return (0);
}

int BitcoinExchange::check_date(std::string tmp)
{
	int i = 0;
	const char *test = tmp.c_str();
	while (test && test[i])
	{
		int tmp = test[i];
		if (!std::isdigit(tmp))
			return (1);
		i++;
	}
	return (0);
}

int BitcoinExchange::check_amount(std::string tmp)
{
	int i = 0;
	int flag = 0;
	const char *test = tmp.c_str();
	while (test && test[i])
	{
		int tmp = test[i];
		if (!std::isdigit(tmp) && test[i] != '.' && test[i] != '-')
			return (1);
		else if (test[i] == '-' && !flag)
			flag += 1;
		else if (test[i] == '-' && flag)
			return (2);
		i++;
	}
	float value = std::stof(tmp);
	if (value < 0)
		return (2);
	else if (value > 1000)
		return (3);
	return (0);
}

float	BitcoinExchange::rate(std::string amount, std::string date)
{
	std::map<std::string, float>::iterator it = reference_database.lower_bound(date);
	std::map<std::string, float>::iterator ite = reference_database.begin();
	for (std::map<std::string, float>::iterator ite = reference_database.begin(); ite != reference_database.end(); ++ite)
	{
		if (ite->first == date)
		{
			float value = std::stof(amount);
			value *= it->second;
			return (value);
		}
	}
	if (reference_database.size() == 1)
	{
		float value = std::stof(amount);
		value *= it->second;
		return (value);
	}
	else if (it == ite)
	{
		float value = std::stof(amount);
		value *= it->second;
		return (value);
	}
	else
	{
		--it;
		float value = std::stof(amount);
		value *= it->second;
		return (value);
	}
}

const char * BitcoinExchange::TooLargeNumber::what() const throw()
{
	return ("Error : too large number.");
}

const char * BitcoinExchange::NotPositiveNumber::what() const throw()
{
	return ("Error : not a positive number.");
}

const char * BitcoinExchange::BadInput::what() const throw()
{
	return ("Error : bad input.");
}
