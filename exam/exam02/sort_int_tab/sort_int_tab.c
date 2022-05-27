void	sort_int_tab(int	*tab, unsigned int size)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	while (j < (int)size)
	{
		i = 0;
		while (tab[i] && tab[i + 1])
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

#include <stdio.h>
int		main(void)
{
	int tab[] = { -1, 6, 7, 3, -6, 7, 2, 4, 5, 2147483647, -2147483648 };
	unsigned int size = 11;

	sort_int_tab(tab, size);

	unsigned int i = 0;
	while (i < size)
	{
		printf("element %d: %d\n", i, tab[i]);
		i++;
	}
	return 0;
}