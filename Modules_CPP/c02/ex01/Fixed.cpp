#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fix = 0;
}

Fixed::Fixed(const	int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fix = value << this->fract;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fix = roundf(value * (1 << fract));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->fix = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits()const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fix);
}

void	Fixed::setRawBits(int const raw)
{
	this->fix = raw;
}

std::ostream& operator<<(std::ostream& dst, const Fixed& src)
{
	dst << src.toFloat();
	return (dst);
}

int	Fixed::toInt(void) const
{
	return (this->fix >> fract);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fix / (1 << fract));
}