#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor get called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(Dog const &other)
{
	if (this != &other)
	{
		std::cout << "Dog copy get called" << std::endl;
		type = other.type;
		brain = new Brain();
		*brain = *other.brain;
	}
}

Dog	&Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain();
		*brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor get called" << std::endl;
	delete brain;
}

void	Dog::setIdea(std::string idea)
{
	brain->setIdea(idea);
}

void	Dog::showIdea()
{
	brain->showIdea();
}
