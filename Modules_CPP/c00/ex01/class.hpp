#ifndef CLASS_HPP
#define	CLASS_HPP

#include <iostream>
#include "phonebook.hpp"

class contact
{
	private:
		std::string 	firstname;
		std::string 	lastname;
		std::string 	nickname;
		std::string 	darkest_secret;
		std::string		phone_nb;
	public:
		int				count;
		std::string access_print(contact	&target, int mod);
		void access_replace(contact	&target, std::string str, int mod);
};

#endif