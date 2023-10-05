#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor get called" << std::endl;
    type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog destructor get called" << std::endl;
}

Dog::Dog(const Dog      &other)
{
    *this = other;
}

Dog&    Dog::operator=(const    Dog&    other)
{
    type = other.type;
	return(*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
