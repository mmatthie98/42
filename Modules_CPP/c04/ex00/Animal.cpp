#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor get called" << std::endl;
	type = "Animal";
}

Animal::Animal(const Animal	&other)
{
	*this = other;
}

Animal::Animal(const std::string	name)
{
	std::cout << "Animal " << name << " constructor get called" << std::endl;
	type = name;
}

Animal&	Animal::operator=(const Animal	&other)
{
	type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor get called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal's sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}
