#include "unistd.h"

int main(int ac, char	**av)
{
	char	*s1;
	char	*s2;
	int		tab[300];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		s1 = av[1];
		s2 = av[2];
		while (i < 300)
		{
			tab[i] = 0;
			i++;
		}
		i = 0;
		while (s1[i])
		{
			j = 0;
			while (s2[j])
			{
				if (s2[j] == s1[i])
				{
					if (tab[(int)s1[i]] == 0)
					{
						write(1, &s2[j], 1);
						tab[(int)s1[i]] = 1;
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
