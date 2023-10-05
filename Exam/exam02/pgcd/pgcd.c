#include <stdio.h>

void	pgcd(int first, int second)
{
	int	i;
	int	gcd;

	i = 1;
	if (first <= 0 || second <= 0)
		return ;
	while (i <= first || i <= second)
	{
		if (first % i == 0 && second % i == 0)
			gcd = i;
		i++;
	}
	printf("%d", gcd);
}

int main(int ac, char	**av)
{
	if (ac == 3)
		pgcd(atoi(av[1]), atoi(av[2]));
	printf("\n");
	return (0);
}
