#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int	fix;
		const	static int	fract = 8;
	public:
		Fixed();
		Fixed(const int	value);
		Fixed(const Fixed& other);
		Fixed(const	float f_value);
		~Fixed();
		Fixed& 	operator=(const Fixed& other);
		float 	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

std::ostream& operator<<(std::ostream& dst, const Fixed& src);

#endif