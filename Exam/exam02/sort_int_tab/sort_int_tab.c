#include <stdio.h>

void	sort_int_tab(int	*tab, unsigned int size)
{
	unsigned int	i;
	int	tmp;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

int main()
{
	int	tab[] = { 3 , 4 , 0, 1 , 6, 42};
	unsigned int	len;
	unsigned int	i;

	len = 6;
	i = 0;
	while (i < len)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
	sort_int_tab(tab, len);
	printf("après\n");
	i = 0;
	while (i < len)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
	return (0);
}