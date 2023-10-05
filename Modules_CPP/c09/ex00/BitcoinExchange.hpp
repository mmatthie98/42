#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <map>
#include <sstream>

class BitcoinExchange
{
	private:
		void parse_file();
	public:
		BitcoinExchange();
		BitcoinExchange(std::string arg);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		std::map<std::string, float>	reference_database;
		std::map<std::string, float>	database;

		float	rate(std::string amount, std::string date);
		void	open_it(std::string file);
		void	parse_it(std::string data);
		int		check_all(std::string date, std::string amount, int flag);
		int		check_amount(std::string amount);
		int		check_date(std::string date);
		class TooLargeNumber : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class NotPositiveNumber : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class BadInput : public std::exception
		{
			public:
				const char * what() const throw();
		};
};