#pragma once
#include "Warlock.hpp"
#include "Aspell.hpp"

class ASpell;

class ATarget
{
	private:
	std::string type;
	public:
	ATarget(std::string type);
	ATarget();
	~ATarget();
	ATarget(const ATarget &other);
	ATarget &ATarget::operator=(const ATarget& other);

	const std::string &getType(); const
	virtual ATarget	*clone() const = 0;
	void	getHitBySpell(const ASpell &other) const;
};