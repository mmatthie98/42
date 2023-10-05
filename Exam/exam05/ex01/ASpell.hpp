#pragma once

#include "Warlock.hpp"

class ASpell
{
	protected:
		std::string name;
		std::string effects;

	public:
		ASpell();
		~ASpell();
		ASpell(const ASpell& other);
		ASpell &operator=(const ASpell& other);
		ASpell(std::string name, std::string effects);
		const std::string getName() const;
		const std::string getEffects() const;
		virtual ASpell* clone() const = 0;
};