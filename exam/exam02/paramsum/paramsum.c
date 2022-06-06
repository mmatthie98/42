#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnb(int nb)
{
	if (nb > 9)
	{
		ft_putnb(nb % 10);
		ft_putnb(nb / 10);
	}
	else
		ft_putchar(nb + 48);
}

int	paramsum(int ac)
{
	ft_putnb(ac);
	return (ac);
}

int main(int ac, char	**av)
{
	int	i;

	i = 0;
	if (ac > 0)
		i = paramsum(ac - 1);
	else 
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}