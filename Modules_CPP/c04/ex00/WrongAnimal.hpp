#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
        protected:
    		std::string     type;
        public:
                WrongAnimal();
                WrongAnimal(const std::string name);
                WrongAnimal(const WrongAnimal        &other);
                ~WrongAnimal();
                WrongAnimal& operator=(const WrongAnimal     &other);
                void makeSound() const;
                std::string getType () const;
};
#endif
