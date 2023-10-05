#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Animal default constructor get called" << std::endl;
	type = "Animal";
}

AAnimal::AAnimal(const AAnimal	&other)
{
	*this = other;
}

AAnimal::AAnimal(const std::string	name)
{
	std::cout << "Animal constructor get called with name" << name << std::endl;
	type = name;
}

AAnimal&	AAnimal::operator=(const AAnimal	&other)
{
	type = other.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor get called" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "Animal's sound" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (type);
}


