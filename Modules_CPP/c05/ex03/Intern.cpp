#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern&	Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm	*Intern::makeForm(std::string nameForm, std::string target)
{
	std::string levels[3];
	levels[0] = "ShrubberyCreationForm";
	levels[1] = "RobotomyRequestForm";
	levels[2] = "PresidentialPardonForm";

	for (int i = 0; i < 2; i++)
	{
		if (levels[i] == nameForm)
		{
			switch (i)
			{
				case (0):
					return (new ShrubberyCreationForm(target));
				case (1):
					return (new RobotomyRequestForm(target));
				case (2):
					return (new PresidentialPardonForm(target));
			}
		}
	}
	std::cout << "the Form you want to duplicate isn't available" << std::endl;
	return (NULL);
}
