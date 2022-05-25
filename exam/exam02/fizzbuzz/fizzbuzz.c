#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnb(int n)
{
	if (n > 9)
	{
		ft_putnb(n / 10);
		ft_putnb(n % 10);
	}
	else
		ft_putchar(48 + n);
}

int	main()
{
	int	i;

	i = 0;
	while (++i <= 100)
	{
		while (i <= 2)
		{
			ft_putnb(i);
			write(1, "\n",1);
			i++;
		}
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz\n", 8);
		else if (i % 5 == 0)
			write(1, "buzz\n", 4);
		else if (i % 3 == 0)
			write(1, "fizz\n", 4);
		else
			ft_putnb(i);
		write (1, "\n", 1);
	}
	return (0);
}