#include "phonebook.hpp"

int main(int ac, char	**av)
{
	phonebook	contacts;
	std::string message;
	int i = 0;

	(void)av;
	if (ac == 1)
	{
		init_tab(&contacts);
		while ("phonebook")
		{
			std::cout << "welcome to the holly phonebook" << std::endl;
			getline(std::cin, message);
			if (std::cin.eof())
				return (1);
			if ((message == "EXIT") || (message == "exit"))
				break ;
			else if ((message == "SEARCH") || (message == "search"))
				phonebook_search(&contacts);
			else if ((message == "ADD") || (message == "add"))
				i = phonebook_add(&contacts, i);
			else
				std::cout << "bro u fuckin' joke? try this [ADD, SEARCH, EXIT]" << std::endl;
		}
	}
}
