#include "iter.hpp"

class Awesome
{
	public:
		Awesome(void): _n(42) { return; }
		int get(void) const {return this->_n; }
	private:
		int _n;	
};
std::ostream &operator<<(std::ostream &o, Awesome const &rhs) { o << rhs.get(); return o;}
template<typename T>
void print(T const &x) { std::cout << x << std::endl; return;}

int main()
{
	int tab[] = { 0, 1, 2, 3, 4};
	char tab3[] = { 'a', 'b', 'c', 'd', 'e'};
	Awesome tab2[5];

	iter(tab, 5, print);
	iter(tab2, 5, print);
	iter(tab3, 5, print);
	return (0);
}

/*int main()
{
	int *tab = new int[3];
	for (int i = 0; i < 3;i++)
		tab[i] = i;
	std::cout << "for int : " << std::endl;
	iter(tab, 3, f);
	char *tab2 = new char[3];
	for (int j = 0; j < 3; j++)
		tab2[j] = 97 + j;
	std::cout << "for char : " << std::endl;
	iter(tab2, 3, f);
	delete[] tab;
	delete[] tab2;
	return (0);
}*/