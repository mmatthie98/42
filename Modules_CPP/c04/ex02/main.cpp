#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "AAnimal.hpp"


int main()
{
	AAnimal *animals[10];
	for (int i = 0; i < 5; i++)
	{
		std::cout << "---------------------" << std::endl;
		animals[i] = new Dog();
	}
	std::cout << "---------------------" << std::endl;
	std::cout << "copy test :" << std::endl;
	{
		Dog basic;
		Dog tmp (basic);
		basic.setIdea("Cat");
		tmp.setIdea("Kitty");
		tmp.showIdea();
		basic.showIdea();
		tmp = basic;
		tmp.showIdea();
		basic.showIdea();
	}
	for (int i = 5; i < 10; i++)
	{
		std::cout << "---------------------" << std::endl;
		animals[i] = new Cat();
	}
	std::cout << "---------------------" << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		std::cout << animals[i]->getType() << std::endl;

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "---------------------" << std::endl;
		delete animals[i];
	}
	std::cout << "---------------------" << std::endl;
	system("leaks AAnimal");
	return 0;
}
