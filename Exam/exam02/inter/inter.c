#include "unistd.h"

int main(int ac, char	**av)
{
	int		tab[125];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (i < 125)
		{
			tab[i] = 0;
			i++;
		}
		i = 0;
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[2][j] == av[1][i])
				{
					if (tab[(int)av[1][i]] == 0)
					{
						write(1, &av[2][j], 1);
						tab[(int)av[1][i]] = 1;
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
