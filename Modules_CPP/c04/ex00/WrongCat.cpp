#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Wrongcat basic constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor get called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat roar!" << std::endl;
}
