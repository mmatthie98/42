#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"


class Dog : public AAnimal
{
	private:
		Brain	*brain;
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog&	other);
		Dog&	operator=(const Dog& other);
		void	showIdea();
		void	setIdea(std::string arg);
		virtual void makeSound() const;
};
#endif
