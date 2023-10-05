#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	test("fedor", 1);
		Bureaucrat  test2("Marie-Laure", 69);
		Bureaucrat  test1("Zizou", 150);
		std::cout << test;
		std::cout << test1;
		std::cout << test2;
		std::cout << "decrease on Marie-Laure :" << std::endl;
		test2.decrease();
		std::cout << test2;
		std::cout << "decrease on fedor :" << std::endl;
		test.decrease();
		std::cout << test;
		std::cout << "increase on fedor :" << std::endl;
		test.increase();
		std::cout << test;
		std::cout << "increase on fedor :" << std::endl;
		test.increase();
		std::cout << test;
		std::cout << "decrease on Zizou :" << std::endl;
		test1.decrease();
		std::cout << test1;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
