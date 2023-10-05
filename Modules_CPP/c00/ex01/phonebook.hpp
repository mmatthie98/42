#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "class.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class phonebook
{
	public:
		contact repertory[8];
};

void	print_index(int index, phonebook	*contact);
void	phonebook_search(phonebook	*contact);
int		phonebook_add(phonebook	*contact, int i);
void	init_tab(phonebook	*contact);

#endif
