#include "Base.hpp"

Base::~Base() {}

Base	*generate(void)
{
	srand(time(NULL));
	int i = rand() % 3;
	switch (i)
	{
		case (0):
		{
			return new A;
			break;
		}
		case (1):
		{
			return new B;
			break;
		}
		case (2):
		{
			return new C;
			break;
		}
	}
	return (NULL);
}

void	identify(Base	*p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "The real type of this Base is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "The real type of this Base is B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "The real type of this Base is C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &ref = dynamic_cast<A &>(p);
		(void)ref;
		std::cout << "The real type of this Base is A" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		try
		{
			B &ref = dynamic_cast<B &>(p);
			(void)ref;
			std::cout << "The real type of this Base is B" << std::endl;	
		}
		catch(const std::bad_cast& bc)
		{
			try
			{
				C &ref = dynamic_cast<C &>(p);
				(void) ref;
				std::cout << "The real type of this Base is C" << std::endl;
			}
			catch(const std::bad_cast& bc)
			{
				std::cout << "Error in the type" << std::endl;
			}
		}
	}
}

