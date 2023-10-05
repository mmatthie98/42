#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string str, int param) : name(str)
{
	if (param < 1)
		throw GradeTooHighException();
	else if (param > 150)
		throw GradeTooLowException();
	else
		grade = param;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
    if (other.grade < 1)
		throw GradeTooHighException();
    else if (other.grade > 150)
		throw GradeTooLowException();
    else
        *this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor get called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat	&other)
{
	grade = other.grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	std::string tmp;
	tmp = name;
	return (tmp);
}

int		Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::increase()
{
	if (grade <= 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		grade--;
}

void	Bureaucrat::decrease()
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade >= 150)
		throw GradeTooLowException();
	else
		grade++;
}

std::ostream& operator<<(std::ostream& dst, const Bureaucrat& src)
{
	dst << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return (dst);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}
