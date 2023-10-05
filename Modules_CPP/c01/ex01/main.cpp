#include "Zombie.hpp"

int main()
{
	Zombie	*z;
	int N = 10;

	z = zombieHorde(N, "Carlo");
	//z->announce();
	for (int i = 0; i < N; i++)
		z->announce();
	delete[] z;
	return (0);
}
