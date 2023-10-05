#include "Data.hpp"

int main()
{
	Data data;
	uintptr_t test = serialize(&data);
	std::cout << "Pointeur d'origine: " << &data << std::endl;
	std::cout << "Adresse serialized: " << test << std::endl;
	std::cout << "Retour deserialize: " << deserialize(test) << std::endl;
	return (0);
}