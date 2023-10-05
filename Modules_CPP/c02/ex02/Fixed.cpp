#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	fix = 0;
}

Fixed::Fixed(const	int value)
{
	// std::cout << "Int constructor called" << std::endl;
	fix = value << fract;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	fix = roundf(value * (1 << fract));
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignement operator called" << std::endl;
	fix = other.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &other)
{
	if (fix > other.fix)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &other)
{
	if (fix < other.fix)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &other)
{
	if (fix <= other.fix)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &other)
{
	if (fix >= other.fix)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &other)
{
	if (fix == other.fix)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &other)
{
	if (fix != other.fix)
		return (true);
	return (false);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits()const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (fix);
}

void	Fixed::setRawBits(int const raw)
{
	fix = raw;
}

std::ostream& operator<<(std::ostream& dst, const Fixed& src)
{
	dst << src.toFloat();
	return (dst);
}

int	Fixed::toInt(void) const
{
	return (fix >> fract);
}

float	Fixed::toFloat(void) const
{
	return ((float)fix / (1 << fract));
}

Fixed	&Fixed::operator+(const	Fixed&	other)
{
	fix += other.fix;
	return (*this);
}

Fixed	&Fixed::operator-(const	Fixed&	other)
{
	fix -= other.fix;
	return (*this);
}

Fixed	Fixed::operator*(const	Fixed&	other)
{
	Fixed tmp;
	tmp.fix = fix * other.fix / (1 << fract);
	return (tmp);
}

Fixed	Fixed::operator/(const	Fixed&	other)
{
	Fixed tmp;
	tmp.fix = fix * (1 << fract) / other.fix;
	return (tmp);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed& 	Fixed::operator++()
{
	++this->fix;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

Fixed& 	Fixed::operator--()
{
	--this->fix;
	return (*this);
}

Fixed	&Fixed::min(Fixed	&first, Fixed	&second)
{
	if (first.fix < second.fix)
		return (first);
	return (second);
}

Fixed	Fixed::min(const Fixed	&first, const Fixed	&second)
{
	Fixed tmp;
	if (first.fix < second.fix)
		tmp = first;
	else
		tmp = second;
	return (tmp);
}

Fixed	&Fixed::max(Fixed	&first, Fixed	&second)
{
	if (first.fix > second.fix)
		return (first);
	return (second);
}

Fixed	Fixed::max(const Fixed	&first, const Fixed	&second)
{
	Fixed tmp;
	if (first.fix > second.fix)
		tmp = first;
	else
		tmp = second;
	return (tmp);
}
