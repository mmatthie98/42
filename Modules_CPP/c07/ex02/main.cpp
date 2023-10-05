#include "Array.hpp"

int main()
{
	try
	{
		//int test
		Array<int> patati;
		Array<int> test(5);
		patati.size();
		test.size();
		//test with empty array
		int * a = new int();
		std::cout << *a << std::endl;
		std::cout << "size of patati: " << patati.size() << std::endl;
		std::cout << "___Int test___" << std::endl;
		std::cout << "size of int test: " << test.size() << std::endl;
		for (unsigned int i = 0;i < test.size(); i++)
			test[i] = i;
		for (unsigned int i = 0;i < test.size(); i++)
			std::cout << "array[" << i << "] = " << test[i] << std::endl;
		//char test
		std::cout << "___char test___" << std::endl;
		Array<char> test1(5);
		test1.size();
		std::cout << "size of char test: " << test1.size() << std::endl;
		for (unsigned int i = 0;i < test1.size(); i++)
			test1[i] = 97 + i;
		for (unsigned int i = 0;i < test1.size(); i++)
			std::cout << "array[" << i << "] = " << test1[i] << std::endl;
		//duplicate test
		Array<int> dup(test);
			std::cout << "___Duplicate test___" << std::endl;
		std::cout << "size of Dup test: " << dup.size() << std::endl;
		for (unsigned int i = 0;i < dup.size(); i++)
			std::cout << "dup array[" << i << "] = " << dup[i] << std::endl;
		//change value of dup
		dup[0] = 42;
		for (unsigned int i = 0;i < dup.size(); i++)
			std::cout << "dup array after change [" << i << "] = " << dup[i] << std::endl;
		std::cout << "looking at the original array : " << std::endl;
		for (unsigned int i = 0;i < test.size(); i++)
			std::cout << "array[" << i << "] = " << test[i] << std::endl;

		//error test
		std::cout << "__Error test__" << std::endl;
		Array<int> test2;
		test2.size();
		std::cout << "size of test1: " << test2.size() << std::endl;
		test2[42] = 42;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return (0);
}