#include "phonebook.hpp"

void contact::access_replace(contact &target, std::string str, int mod)
{
	if (mod == 0)
		target.firstname = str;
	else if (mod == 1)
		target.lastname = str;
	else if (mod == 2)
		target.nickname = str;
	else if (mod == 3)
		target.darkest_secret = str;
	else if (mod == 4)
		phone_nb = str;
}

std::string	contact::access_print(contact	&target, int mod)
{
	std::string tmp;
	
	if (mod == 0)
		tmp = target.firstname;
	else if (mod == 1)
		tmp = target.lastname;
	else if (mod == 2)
		tmp = target.nickname;
	else if (mod == 3)
		tmp = target.darkest_secret;
	else if (mod == 4)
		tmp = phone_nb;
	return (tmp);
}

void	print_index(int index, phonebook	*contact)
{
	std::cout << "Firstname : ";
	std::cout << contact->repertory[index].access_print(contact->repertory[index], 0) << std::endl;
	std::cout << "Lastname : ";
	std::cout << contact->repertory[index].access_print(contact->repertory[index], 1) << std::endl;
	std::cout << "Nickname : ";
	std::cout << contact->repertory[index].access_print(contact->repertory[index], 2) << std::endl;
	std::cout << "Darkest secret : ";
	std::cout << contact->repertory[index].access_print(contact->repertory[index], 3) << std::endl;
	std::cout << "Phone_nb : ";
	std::cout << contact->repertory[index].access_print(contact->repertory[index], 4) << std::endl;
}

void	get_the_rest(phonebook	*contact, int i)
{
	std::string msg;
	std::cout << "Lastname : " << std::endl;
	getline(std::cin, msg);
	if (std::cin.fail())
	{
		std::cout << "lastname failed " << std::endl;
		exit (-1);
	}
	else if (msg.empty())
	{
		std::cout << "please don't use empty slot" << std::endl;
		exit (-1);
	}
	contact->repertory[i].access_replace(contact->repertory[i], msg, 1);
	std::string message;
	std::cout << "Nickname : " << std::endl;
	getline(std::cin, message);
	if (std::cin.fail())
	{
		std::cout << "Nickname failed " << std::endl;
		exit (-1);
	}
	else if (message.empty())
	{
		std::cout << "please don't use empty slot" << std::endl;
		exit (-1);
	}
	contact->repertory[i].access_replace(contact->repertory[i], message, 2);
	std::string m;
	std::cout << "Deapest secret's : " << std::endl;
	getline(std::cin, m);
	if (std::cin.fail())
	{
		std::cout << "secret failed " << std::endl;
		exit (-1);
	}
	else if (m.empty())
	{
		std::cout << "please don't use empty slot" << std::endl;
		exit (-1);
	}
	contact->repertory[i].access_replace(contact->repertory[i], m, 3);
	std::cout << "number phone : " << std::endl;
	std::string mesg;
	getline(std::cin, mesg);
	if (std::cin.fail())
	{
		std::cout << "number failed " << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else if (mesg.empty())
	{
		std::cout << "please don't use empty slot" << std::endl;
		exit (-1);
	}
	contact->repertory[i].access_replace(contact->repertory[i], mesg, 4);
	std::cout << "___alright contact added___" << std::endl;
}

int	phonebook_add(phonebook	*contact, int i)
{
	if (i == 8)
	{
		std::cout << "reset" << std::endl;
		i = 0;
	}
	std::string msg;
	std::cout << "Firstname : " << std::endl;
	if (getline(std::cin, msg))
	{
		if (msg.empty())
		{
			std::cout << "please don't use empty slot" << std::endl;
			return (i);
		}
		contact->repertory[i].access_replace(contact->repertory[i], msg, 0);
		get_the_rest(contact, i);
	}
	else
	{
		std::cout << "please use valid character's" << std::endl;
		return (i);
	}
	contact->repertory[i].count = 0;
	i++;
	return (i);
}

void	set_tab(phonebook	*contact)
{
	std::size_t i;

	int loop = 0;
	while (loop < 8)
	{
		int check = 0;
		if (!contact->repertory[loop].count)
		{
			std::cout << std::setfill(' ') << std::setw(9) << loop << " |";
			for (int j = 0; j < 4; j++)
			{
				i = contact->repertory[loop].access_print(contact->repertory[loop], j).length();
				if (i > 10)
				{
					while (check < 9)
					{
						std::cout << contact->repertory[loop].access_print(contact->repertory[loop], j)[check];
						check++;
					}
					std::cout << ".|";
				}
				else
				{
					while (i < 10)
					{
						check++;
						i++;
					}
					while (check)
					{
						std::cout << " ";
						check--;
					}
					std::cout << contact->repertory[loop].access_print(contact->repertory[loop], j) << "|";
				}
				check = 0;
				i = 0;
			}
			loop++;
			std::cout << std::endl;
		}
		else
		{
			std::cout << std::setfill(' ') << std::setw(8);
			std::cout << "End of the repertory !" << std::endl;
			return ;
		}
	}
}

void	phonebook_search(phonebook	*contact)
{
	int index;

	set_tab(contact);
	std::cout << "please insert an index : " << std::endl;
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cout << "please use an index between >= 0 && index <= 7" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else if (index >= 0 && index <= 7)
	{
		if (contact->repertory[index].count != -1)
		{
			print_index(index, contact);
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cout << "the index u put is empty" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	else
	{
		std::cout << "please use an index >= 0 && index <= 7" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
}

void	init_tab(phonebook	*contact)
{
	int i = 0;

	while (i <= 7)
	{
		contact->repertory[i].count = -1;
		i++;
	}
}
