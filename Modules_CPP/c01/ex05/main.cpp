#include "Harl.hpp"

int main()
{
	Harl harl;

	harl.complain("DEBUG");
	std::cout << "___" << std::endl;
	harl.complain("INFO");
	std::cout << "___" << std::endl;
	harl.complain("WARNING");
	std::cout << "___" << std::endl;
	harl.complain("ERROR");
	std::cout << "___" << std::endl;
	harl.complain("lol");
	harl.complain("xD");
	return (0);
}