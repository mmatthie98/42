#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	try
	{
		Bureaucrat	test("fedor", 1);
		Bureaucrat  test2("Marie-Laure", 70);
		Bureaucrat  test1("Zizou", 150);
		Form		formulaire("b55", 70, 60);
		Form		formulaire1("c55", 2, 150);

		std::cout << test;
		std::cout << test1;
		std::cout << test2;
		test2.decrease();
		std::cout << test2;
		test2.increase();
		test.decrease();
		std::cout << test;
		//test.increase();
		//std::cout << test;
		formulaire.beSigned(test2);
		formulaire.beSigned(test2);
		//test2.decrease();
		//formulaire.beSigned(test2);
		formulaire1.beSigned(test);
		formulaire1.beSigned(test2);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
