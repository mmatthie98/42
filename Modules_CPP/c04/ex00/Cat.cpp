#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor get called" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor get called" << std::endl;
}

Cat::Cat(const Cat	&other)
{
	*this = other;
}

Cat&	Cat::operator=(const	Cat&	other)
{
	type = other.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
