#include <stdlib.h>
#include <stdio.h>
/*
static int	get_the_len(int start, int end)
{
	int	i;

	i = 0;
	if (start != end)
	{
		if (start < end)
		{
			while (start <= end)
			{
				i++;
				start++;
			}
		}
		else if (start > end)
		{
			while (start >= end)
			{
				i++;
				start--;
			}
		}
	}
	else
		i = 1;
	return (i);
}

static int check_sense(int	start, int end)
{
	int	i;

	i = 0;
	if (start > end)
		i = 1;
	if (start < end)
		i = -1;
	return (i);
}*/

int	*ft_range(int	start, int end)
{
	int	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(int) * i + 1);
	while (start < end)
	{
		str[i] = start;
		start++;
		i++;
	}
	str[i] = start;
	while (start > end)
	{
		str[i] = start;
		start--;
		i++;
	}
	str[i] = start;
	return (str);
}

// bug with negative numbers
int main()
{
	int	*tab;
	int	i;
	int	j;
	int k;

	i = 1;
	j = -4;
	k = 0;
	tab = ft_range(i, j);
	while (tab[k])
	{
		printf("tab[k] : %d\n", tab[k]);
		k++;
	}
	return (0);
}