#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*int	*ft_range(int	start, int end, int k)
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
}*/

int	*ft_range2(int start, int end) {
	int range = start - end;
	if (range < 0)
		range *= -1;
	range++;

	int * tab = malloc(sizeof(int) * range);

	int step;
	if (start > end)
		step = -1;
	else
		step = 1;

	int i = 0;
	while (start != end) {
		tab[i] = start;
		start += step;
		i++;
	}
	tab[i] = start;

	return (tab);
}

/*
int	*get_range_up(int	*tab, int	range, int start)
{
	int	i;
	int	j;
	int	step;

	j = 0;
	i = start;
	while (j < range)
	{
		//int * x = malloc(4);
		//x = i;
		tab[j] = i;
		j++;

		i--;
	}
	return(tab);
}
*/

/*int	*get_range_down(int	*tab, int range, int start)
{
	int	i;
	int	j;


	j = 0;
	i = start;
	while (j < range)
	{
		//int * x = malloc(4);
		//x = i;
		tab[j] = i;
		j++;
		i++;
	}
	return(tab);
}

int	get_range(start, end) {
	int	i;

	i = 0;
	if (start > end)
	{
		while (start - i >= end)
			i++;
	}
	else if (end > start)
	{
		while (end - i >= start)
			i++;
	}
	else
		i = 1;
	return (i);
}


int	*get_range_mixte(int	*tab, int range, int start, int step)
{
	int	i;
	int	j;
	int	step;

	j = 0;
	i = start;
	if (step == 2)
	{
		while (j < range)
		{
			tab[j] = i;
			j++;
			i--;
		}
	}
	if (step == 1)
	{
		while (j < range)
		{
			tab[j] = i;
			j++;
			i--;
		}
	}
	return(tab);
}/

int	*ft_range(int	start, int end)
{
	int	*tab;
	int	i;
	int	step;

	tab = NULL;
	i = 0;
	i = get_range(start, end);
	step = 0;
	tab = malloc(sizeof(int) * i);
	if (start > end)
	{
		step = 1;
		tab = get_range_mixte(tab, i, start, step);
	}
	else if (start < end)
	{
		step = -;
		tab = get_range_mixte(tab, i, start, step);
	}
	else
		tab[0] = start;
	return (tab);
}

/

int => 4 bytes:

int * ptr;

*ptr = 2;

int ** [
	ptr(*ptr = 2), j = 0
	ptr(*ptr = 2), j = 1
	ptr(*ptr = 2) j = 2

]

int ** [
	[
		0000 0000 | 0000 0000 | 0000 0000 | 0000 0000, a
		0000 0000 | 0000 0000 | 0000 0000 | 0000 0000, b
		0000 0000 | 0000 0000 | 0000 0000 | 0000 0000, c
		0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 d
	],
	[
		0000 0000 | 0000 0000 | 0000 0000 | 0000 0000, a
		0000 0000 | 0000 0000 | 0000 0000 | 0000 0000, b
		0000 0000 | 0000 0000 | 0000 0000 | 0000 0000, c
		0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 d
	]
]

int * 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000

int * [
	0000 0000 | 0000 0000 | 0000 0000 | 0000 0000, a
	0000 0000 | 0000 0000 | 0000 0000 | 0000 0000, b
	0000 0000 | 0000 0000 | 0000 0000 | 0000 0000, c
	0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 d
]

x = &a
*x = a

x + 4 = &b

int	*x => [a, b, c, d];

char *	s = 'c' 'b' 'a' '\0'
char ** strs = "slt" "mdr" NULL
int * int_tab = 0 1 2 3 4  => 5
int ** int_tabtab = [0 1 2 5] [14 54 8] NULL

*/


int main()
{
	int	*tab;
	int	start;
	int	end;
	int l;
	int	i;

	i = 0;
	start = -5;
	end = -8;
	l = (start - end > 0) ? start - end + 1 : end - start + 1;
	//l = get_range(start, end);
	tab = ft_range2(start, end);
	//printf("tab : %d\n", *tab);
	//printf("tab -> \n");
	while (i < l)
	{
		printf("tab[i] : %d\n", tab[i]);
		i++;
	}
	return (0);
}
