#include "Form.hpp"

Form::Form() : name("Default"),signature(false), grade_to_sign(150), grade_to_execute(150) {}

Form::Form(std::string name, int signe, int exec) : name(name), grade_to_sign(signe), grade_to_execute(exec)
{
	if (signe < 1 || exec < 1)
		throw GradeTooHighException();
	else if (signe > 150 || exec > 150)
		throw GradeTooLowException();
	else
		signature = false;
}

Form::~Form() {}

Form::Form(const Form &other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	signature = other.signature;
	if (other.grade_to_execute < 1 || other.grade_to_sign < 1)
		throw GradeTooHighException();
	else if (other.grade_to_execute > 150 || other.grade_to_sign > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form	&other)
{
	if (this != &other)
		signature = other.signature;
	return (*this);
}

bool	Form::getSignature() const
{
	if (signature == true)
		return (true);
	return (false);
}

int	Form::getGradeToSign() const
{
	int tmp = 0;
	tmp = this->grade_to_sign;
	return (tmp);
}

void	Form::beSigned(Bureaucrat const	&bur)
{
	int i = bur.getGrade();
	if (i <= this->grade_to_sign)
		bur.signForm(*this);
	else
		throw GradeTooLowException();
}

std::string Form::getName() const
{
	std::string tmp;
	tmp = name;
	return (tmp);
}

void	Form::changesign()
{
	signature = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}
