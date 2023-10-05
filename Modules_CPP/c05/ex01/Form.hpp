#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	public:
		Form();
		Form(std::string name, int signe, int exec);
		~Form();
		Form(const Form	&other);
		Form&		operator=(const Form &other);
		void		beSigned(Bureaucrat const &bur);
		bool		getSignature() const;
		std::string getName() const;
		int			getGradeToSign() const;
		void		changesign();
	public:
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
	private:
		const	 		std::string name;
		bool			signature;
		const	int		grade_to_sign;
		const	int		grade_to_execute;
};
#endif
