#include "Base.hpp"

int main()
{
	try
	{
		Base	*ptr = generate();
		std::cout << std::endl;
		std::cout << "first identify : ";
		identify(ptr);
		std::cout << std::endl;
		std::cout << "second identify : ";
		identify(*ptr);
		std::cout << std::endl;
		delete ptr;
		//std::cout << "error test : ";
		// Error handling
		/*int *null_test = NULL;
		identify(NULL);
		Base null_base = *reinterpret_cast<Base *>(null_test);
		identify(null_base);
		std::cout << std::endl;*/
	}
	catch (const std::bad_cast &bc)
	{
		std::cerr << bc.what() << std::endl;
	}
	return (0);
}