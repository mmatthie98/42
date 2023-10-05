#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor get called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor get called" << std::endl;
}

Brain::Brain(const Brain	&other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
}

Brain&	Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return (*this);
}

void	Brain::showIdea()
{
	std::cout << "Ideas : " << this->ideas[0] << std::endl;
}

void	Brain::setIdea(std::string idea)
{
	this->ideas[0] = idea;
}
