#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const	ShrubberyCreationForm	&other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		void	print_tree(Bureaucrat	const	&bur) const;
		void	execute(Bureaucrat const	&exec) const;
};
#endif
