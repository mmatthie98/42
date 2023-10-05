#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	DiamondTrap Dia("Dia");
	ScavTrap	Scav;
	std::cout << "whoami__ "<< std::endl;
	Dia.whoami();
	/*std::cout << "Dia use check_hp : " << Dia.check_hp(Scav) << std::endl;
	std::cout << "Dia.attack1___"<< std::endl;
	Dia.attack("Scav");
	Scav.takeDamage(30);
	std::cout << "Dia use check_hp : " << Dia.check_hp(Scav) << std::endl;
	std::cout << "Dia.attack2___"<< std::endl;
	Dia.attack("Scav");
	Scav.takeDamage(30);
	std::cout << "Dia use check_hp : " << Dia.check_hp(Scav) << std::endl;
	std::cout << "Dia.attack3___"<< std::endl;
	Dia.attack("Scav");
	Scav.takeDamage(30);
	std::cout << "Dia use check_hp : " << Dia.check_hp(Scav) << std::endl;
	std::cout << "Dia.attack4___"<< std::endl;
	Dia.attack("Scav");
	Scav.takeDamage(30);
	std::cout << "Dia use check_hp : " << Dia.check_hp(Scav) << std::endl;
	std::cout << "Scav attack Dia___" << std::endl;
	Scav.attack("Dia");
	std::cout << "Dia use check_hp : " << Dia.check_hp(Dia) << std::endl;*/
	std::cout << "Dia use guardGate___"<< std::endl;
	Dia.guardGate();
	std::cout << "Dia use highfive___"<< std::endl;
	Dia.highfive();
	return (0);
}
