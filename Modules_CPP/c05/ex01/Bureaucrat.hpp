#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int		grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string str, int param);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		std::string getName() const;
		int			getGrade() const;
		void		increase();
		void		decrease();
		void 		signForm(Form &form) const;
	public:
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what () const throw();
		};
};

std::ostream& operator<<(std::ostream& dst, const Bureaucrat& src);
#endif
