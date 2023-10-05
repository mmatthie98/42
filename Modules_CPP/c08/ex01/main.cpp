#include "Span.hpp"

int main()
{
	Span sp = Span(10000);
	sp.fill_it(9998, 42);
	sp.addNumber(21);
	sp.addNumber(84);
	//std::cout << "sp.size() = " << sp.get_size() << std::endl;
	sp.print_it();
	//std::cout << sp.shortestSpan() << std::endl;
	//std::cout << sp.longestSpan() << std::endl;
}
/*int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}*/
/*int main()
{
	Span test(3);
	Span test1;
	Span test2(5);
	try
	{
		std::cout << "test for 3 slot add numbers to it:" << std::endl;
		test.addNumber(2);
		test.addNumber(5);
		test.addNumber(42);
		std::cout << "print the content of test :" << std::endl;
		test.print_it();
		std::cout << "Duplicate test to test1(empty) with =" << std::endl;
		test1 = test;
		std::cout << "Print the duplicate test1" << std::endl;
		test1.print_it();
		std::cout << "the shortest diff in the vector is : " << test1.shortestSpan() << std::endl;
		std::cout << "the longest diff in the vector is : " << test1.longestSpan() << std::endl;
		std::cout << "Try to use the fill_it() on test2" << std::endl;
		test2.fill_it(5, 42);
		std::cout << "test2 content : " << std::endl;
		test2.print_it();
		std::cout << "Looking for the copy" << std::endl;
		Span test3(test1);
		test3.print_it();
		std::cout << "Try to overwrite on test" << std::endl;
		test.addNumber(04);
	}
	catch (std::string &e)
	{
		std::cerr << e << std::endl;
	}
	return (0);
	
}*/