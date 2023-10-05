#include <unistd.h>
#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == '\v' || c == '\n' || c == '\t' || c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char	*str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	if (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
}

int	ft_is_op(char	*c)
{
	int	i;

	i = 0;
	while (c && c[i])
	{
		if (c[i] == '+')
			return (1);
		else if (c[i] == '-')
			return (2);
		else if (c[i] == '/')
			return (3);
		else if (c[i] == '*')
			return (4);
		i++;
	}
	return (0);
}

int	do_op(int a, char *c, int b)
{
	if (ft_is_op(c) == 1)
		printf("%d.\n", a + b);
	else if (ft_is_op(c) == 2)
		printf("%d.\n", a - b);
	else if (ft_is_op(c) == 3)
		printf("%d.\n", a / b);
	else if (ft_is_op(c) == 4)
		printf("%d.\n", a * b);
	return (0);
}

int main(int ac, char	**av)
{
	int		a;
	int		b;
	int		opp;

	if (ac == 4)
	{
		a = ft_atoi(av[1]);
		b = ft_atoi(av[3]);
		opp = ft_is_op(av[2]);
		if (a && b && opp)
			do_op(a, av[2], b);
	}
	//printf("ac : %d.\n", ac);
	return (0);
}
