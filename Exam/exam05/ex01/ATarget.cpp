#include "ATarget.hpp"

ATarget::ATarget(std::string type) : type(type) {}



void ATarget::getHitBySpell(const ASpell &other) const
{
	std::cout << type << " has been " << other.getEffects() << std::endl;
}