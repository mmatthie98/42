#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm	&other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm	&other);
		void execute(Bureaucrat const &exec) const;
		void empeachment(Bureaucrat const &bur) const;
	private:
		std::string name;
};
#endif