#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5), name("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), name(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return (*this);
}

void	PresidentialPardonForm::empeachment(Bureaucrat const &exec) const
{
	(void) exec;
	std::cout << name << " is forgiven by Zaphod Beeblebrox." << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &exec) const
{
	AForm::execute(exec);
	empeachment(exec);
}