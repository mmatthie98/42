#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor get called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const	Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		brain = new Brain();
		*brain = *(other.brain);
	}
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain();
		*brain = (*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Dog constructor get called" << std::endl;
	delete brain;
}

void	Cat::setIdea(std::string idea)
{
	brain->setIdea(idea);
}

void	Cat::showIdea()
{
	brain->showIdea();
}

