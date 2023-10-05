#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(1);
	Fixed d(10);
	std::cout << a.getRawBits() << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << a << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "Max and min : " << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	if (c < a)
		std::cout << "c is inferior" << std::endl;
	else
		std::cout << "c is superior" << std::endl;

	if (c > a)
		std::cout << "c is superior" << std::endl;
	else
		std::cout << "c is inferior" << std::endl;

	if (c <= a)
		std::cout << "c is inferior or equal" << std::endl;
	else
		std::cout << "c is superior" << std::endl;

	if (c >= a)
		std::cout << "c is superior or equal" << std::endl;
	else
		std::cout << "c is inferior" << std::endl;

	if (c == c)
		std::cout << "they are the same" << std::endl;

	if (c != a)
		std::cout << "they are different" << std::endl;

	std::cout << "c + b : " << c + b << std::endl;

	std::cout << "c - b : " << c - b << std::endl;

	std::cout << "c : " << c << std::endl;
	std::cout << "d : " << d << std::endl;
	std::cout << "c * d : " << c * d << std::endl;
	std::cout << "d / c : " << d / c << std::endl;
	return 0;
}
