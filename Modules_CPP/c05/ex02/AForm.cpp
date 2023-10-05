#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), grade_to_sign(150), grade_to_execute(150)
{
	signature = false;
}

AForm::AForm(std::string name, int signe, int exec) : name(name), grade_to_sign(signe), grade_to_execute(exec)
{
	if (signe < 1 || exec < 1)
		throw GradeTooHighException();
	else if (signe > 150 || exec > 150)
		throw GradeTooLowException();
	else
		signature = false;
}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	signature = other.signature;
	if (other.grade_to_execute < 1 || other.grade_to_sign < 1)
		throw GradeTooHighException();
	else if (other.grade_to_execute > 150 || other.grade_to_sign > 150)
		throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm	&other)
{
	if (this != &other)
		signature = other.signature;
	return (*this);
}

bool	AForm::getSignature() const
{
	if (signature == true)
		return (true);
	return (false);
}

int	AForm::getGradeToSign() const
{
	int tmp = 0;
	tmp = this->grade_to_sign;
	return (tmp);
}

void	AForm::beSigned(Bureaucrat const	&bur)
{
	int i = bur.getGrade();
	if (i <= this->grade_to_sign)
		bur.signForm(*this);
	else
		throw GradeTooLowException();
}

std::string AForm::getName() const
{
	std::string tmp;
	tmp = name;
	return (tmp);
}

void	AForm::changesign()
{
	signature = true;
}

void	AForm::execute(Bureaucrat const &exec) const
{
	if (this->getSignature() == false)
		throw Bureaucrat::FormNotSigned();
	else if (exec.getGrade() > grade_to_execute)
		throw GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}
