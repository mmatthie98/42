#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>
class Base
{
	public:
		virtual ~Base();
};
class A : public Base{};
class B : public Base{};
class C : public Base{};

Base *generate(void); /*Elle crée aléatoirement une instance de A, B ou C et la retourne en tant que pointeur sur
Base. Utilisez ce que vous souhaitez pour l’implémentation du choix aléatoire.*/
void identify(Base* p); //Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C".
void identify(Base& p); //Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C". pointeur interdit.
#endif