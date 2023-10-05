#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongAnimal();
	const WrongAnimal* l = new WrongCat();
	const WrongCat* m = new WrongCat();
	std::cout << "type : ";
	std::cout << meta->getType() << " | sound : ";
	meta->makeSound();
	std::cout << "type : ";
	std::cout << j->getType() << " | sound :";
	j->makeSound();
	std::cout << "type : ";
	std::cout << i->getType() << " | sound :";
	i->makeSound(); //will output the cat sound!
	std::cout << "type : ";
	std::cout << k->getType() << " | sound :";
	k->makeSound();
	std::cout << "type : ";
	std::cout << l->getType() << " | sound :";
	l->makeSound();
	std::cout << "type : ";
	std::cout << m->getType() << " | sound :";
	m->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	delete k;
	delete l;
	delete m;
	system("leaks Animal");
	return 0;
}
