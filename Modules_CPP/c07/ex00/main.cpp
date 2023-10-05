#include "whatever.hpp"
/*
class Awesome
{
	public:
		Awesome(void): _n(0) {}
		Awesome(int n): _n(n) {}
		Awesome& operator=(Awesome & a) { _n = a._n; return (*this);}
		bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n);}
		bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n);}
		bool operator>(Awesome const &rhs) const { return(this->_n > rhs._n);}
		bool operator<(Awesome const &rhs) const { return(this->_n < rhs._n);}
		bool operator>=(Awesome const &rhs) const { return(this->_n >= rhs._n);}
		bool operator<=(Awesome const &rhs) const { return(this->_n <= rhs._n);}
		int get_n() const { return (_n);}
	private:
		int _n;
};
std::ostream& operator<<(std::ostream &o, const Awesome &a) { o << a.get_n(); return o;}

int main(void)
{
	Awesome a(2), b(4);

	std::cout << a << " " << b << std::endl;
	swap(a, b);
	std::cout << a << " " << b << std::endl;
	std::cout << max(a,b) << std::endl;
	std::cout << min(a,b) << std::endl;
	return (0);
}*/

int main( void ) 
{
	int a = 2;
	int b = 3;
	int z = 2;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << ", z = " << z << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "max( a, z ) with equal = " << ::max( a, z ) << std::endl;
	std::cout << "min( a, z ) with equal = " << ::min( a, z ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::string e = "chaine1";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << ", e = " << e << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "max( e, d ) with equal = " << ::max( e, d ) << std::endl;
	std::cout << "min( d, e ) with equal = " << ::min( d, e ) << std::endl;
	return (0);
}

/*int main()
{
	//char x = 'a';
	// char y = 'b';
	// char z = 'a';
	//int x = 1;
	//int y = 1;
	//int z = 1;
	float x = 0.987;
	float y = 0.988;
	float z = 0.987;

	//std::cout << "before : x = " << x << " && y = " << y << std::endl;
	//swap(x, y);
	//std::cout << "after swap : x = " << x << " && y = " << y << std::endl;
	std::cout << "the max one is : " << max(x, y) << std::endl;
	std::cout << "the min one is : " << min(x, y) << std::endl;
	std::cout << "the max one with equal is : " << max(x, z) << std::endl;
	std::cout << "the min one with equal is : " << min(x, z) << std::endl;
}*/