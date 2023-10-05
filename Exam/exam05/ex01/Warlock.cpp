#include "Warlock.hpp"

Warlock::~Warlock() {
	std::cout << name << " : my job here is done!" << std::endl;
}

Warlock::Warlock(std::string name, std::string title) : name(name) , title(title) {
	std::cout << name << " : This look like another boring day." << std::endl;
}

const std::string& Warlock::getName() const
{
	return (name);
}

const std::string& Warlock::getTitle() const
{
	return (title);
}

void Warlock::setTitle(const std::string &newtitle)
{
	title = newtitle;	
}

void Warlock::introduce() const
{
	std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}