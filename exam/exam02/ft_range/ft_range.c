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

int	*ft_range(int	start, int end, int k)
{
	int	*str;
	int		i;

	i = 0;
	if (start >= end)
	{
		while (start >= end)
		{
			i++;
			start--;
		}
	}
	else if (end >= start)
	{
		while (end >= start)
		{
			i++;
			start--;
		}
	}
	str = malloc(sizeof(int) * i + 1);
	i = 0;
	if (k <= end)
	{
		while (k <= end)
		{
			str[i] = k;
			k++;
			i++;
		}
	}
	if (k >= end)
	{
		while (k >= end)
		{
			str[i] = k;
			k--;
			i++;
		}
	}
	return (str);
}

// bug with negative numbers
/*int main()
{
	int	*tab;
	int	start;
	int	end;
	int k;
	int l;

	start = 1;
	end = -4;
	k = start;
	l = 0;
	tab = ft_range(start, end, k);
	while (tab[l])
	{
		printf("tab[l] : %d\n", tab[l]);
		l++;
	}
	return (0);
}
*/
