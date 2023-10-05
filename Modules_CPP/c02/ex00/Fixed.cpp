#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fix = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "copy constructor called" << std::endl;
	fix = other.fix;
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	fix = other.fix;
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
	fix = raw;
}