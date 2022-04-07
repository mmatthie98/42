#include <unistd.h>

int main(int ac, char	**av)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int		tab[300];
	int		i;

	i = 0;
	if (ac == 3)
	{
		s1 = (unsigned char*)av[1];
		s2 = (unsigned char*)av[2];
		while (i < 300)
		{
			tab[i] = 0;
			i++;
		}
		i = 0;
		while (s1[i])
		{
			if (tab[s1[i]] == 0)
			{
				write(1, &s1[i], 1);
				tab[s1[i]] = 1;
			}
			i++;
		}
		i = 0;
		while (s2[i])
		{
			if (tab[s2[i]] == 0)
			{
				write(1, &s2[i], 1);
				tab[s2[i]] = 1;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
