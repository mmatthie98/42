#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected :
		std::string	type;
	public:
		AAnimal();
		AAnimal(const std::string name);
		AAnimal(const AAnimal	&other);
		virtual ~AAnimal();
		AAnimal&	operator=(const AAnimal	&other);
		virtual void	makeSound() const = 0;
		virtual std::string	getType() const;
};
#endif
