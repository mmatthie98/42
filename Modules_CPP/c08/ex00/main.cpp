#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> vect;
		vect.push_back(4);
		vect.push_back(2);
		vect.push_back(-42);
		std::cout << "vector is there !" << std::endl;
		if (easyfind(vect, 4))
			std::cout << "1:ok !" << std::endl;
		if (easyfind(vect, 2))
			std::cout << "2:ok !" << std::endl;
		if (easyfind(vect, -42))
			std::cout << "3:ok !" << std::endl;
		if (easyfind(vect, 4))
			std::cout << "4:ok !" << std::endl;
		if (easyfind(vect, 41))
			std::cout << "5:ok !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

/*int main()
{
	try
	{
		std::list<int> lst;
		lst.push_back(4);
		lst.push_back(2);
		lst.push_back(-42);

		if (easyfind(lst, -42))
			std::cout << "1:ok !" << std::endl;
		if (easyfind(lst, 4))
			std::cout << "2:ok !" << std::endl;
		if (easyfind(lst, 2))
			std::cout << "3:ok !" << std::endl;
		if (easyfind(lst, -42))
			std::cout << "4:ok !" << std::endl;
		if (easyfind(lst, 41))
			std::cout << "5:ok !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
}*/