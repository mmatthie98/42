#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	public:
		AForm();
		AForm(std::string name, int signe, int exec);
		~AForm();
		AForm(const AForm	&other);
		AForm&	operator=(const AForm &other);
		void	beSigned(Bureaucrat const &bur);
		bool	getSignature() const;
		std::string getName() const;
		int			getGradeToSign() const;
		void		changesign();
		virtual void	execute(Bureaucrat const &execute) const;
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
