#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
class Data
{
	public:
		Data();
		~Data();
		Data(const Data	&other);
		Data& operator=(const Data	&other);
	private:
		uintptr_t test;
};
uintptr_t serialize(Data* ptr); //Elle prend un pointeur et convertit celui-ci vers le type d’entier non-signé uintptr_t.
Data* deserialize(uintptr_t raw); //Écrivez un programme pour tester vos fonctions et vous assurer que tout marche comme attendu
#endif