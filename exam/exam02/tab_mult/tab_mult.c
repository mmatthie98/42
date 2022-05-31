#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char	*str)
{
	int	i;
	int neg;
	int res;

	neg = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] == '+' || str[i] == '-')
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

void	ft_putnb(int nb)
{
	if (nb > 9)
	{
		ft_putnb(nb / 10);
		ft_putnb(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_tab_mult(int i)
{
	int	j;
	int res;

	j = 0;
	while (++j < 10)
	{
		res = i * j;
		ft_putnb(i);
		write(1, " * ", 3);
		ft_putnb(j);
		write(1, " = ", 3);
		ft_putnb(res);
		write(1, "\n", 1);
	}
}


int	main(int ac, char	**av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		i = ft_atoi(av[1]);
		ft_tab_mult(i);
	}
	else
		write(1, "\n", 1);
	return (0);
}