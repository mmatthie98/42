#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45), name("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), name(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm	&other) : AForm(other) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return (*this);
}

void	RobotomyRequestForm::init_robot(Bureaucrat	const &bur) const
{
	(void) bur;
	srand(time(0));
	int i = rand();

	if (i % 2 == 0)
	{
		std::cout << "Bzzzz, Bzzzz " << name << " is a cyborg right now!" << std::endl;
		return ;
	}
	std::cout << name << " is protected from cyborg transformation!" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &exec) const
{
	AForm::execute(exec);
	init_robot(exec);
}