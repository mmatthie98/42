#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 147), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 147), target(name) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const	ShrubberyCreationForm	&other) : AForm(other) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm	&other)
{
	AForm::operator=(other);
	return (*this);
}

void ShrubberyCreationForm::print_tree(Bureaucrat const	&bur) const
{
	(void) bur;
	std::ofstream file (target + "_shrubbery");
	if (file.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			file << "___ Christma's tree ___"  << std::endl;
			file << "   _--_  " << std::endl;
			file << "  |    |" << std::endl;
			file <<	" |      |" << std::endl;
			file << "(        )" << std::endl;
			file << " | _--_ |" << std::endl;
			file << "  |    |" << std::endl;
			file <<	"   |  |" << std::endl;
			file <<	"   |  |" << std::endl;
			file << "   |  |" << std::endl;
		}
	}
	file.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const &exec) const
{
	AForm::execute(exec);
	print_tree(exec);
}