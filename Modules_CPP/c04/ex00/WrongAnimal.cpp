#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const std::string name)
{
	std::cout << "WrongAnimal second constructor called" << std::endl;
	type = name;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal	&other)
{
	type = other.type;
	return(*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal's roar!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}
