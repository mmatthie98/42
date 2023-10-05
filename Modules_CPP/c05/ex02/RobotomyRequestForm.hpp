#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <time.h>


class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm	&other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm	&other);
		void	execute(Bureaucrat const &exec) const;
		void	init_robot(Bureaucrat const &bur) const;
	private:
		std::string name;	
};
#endif