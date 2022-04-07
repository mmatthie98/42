#include <unistd.h>

char	ft_putchar(char	c)
{
	write(1, &c, 1);
	return(0);
}

int	rotone(char	*str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'y')
			ft_putchar(str[i] + 1);
		else if (str[i] == 'z')
			ft_putchar(str[i] - 25);
		else if (str[i] >= 'A' && str[i] <= 'Y')
			ft_putchar(str[i] + 1);
		else if (str[i] == 'Z')
			ft_putchar(str[i] - 25);
		else
			ft_putchar(str[i]);
		i++;
	}
	return(0);
}

int main(int ac, char **av)
{
	char	*str;
	if (ac > 1)
	{
		str = av[1];
		if (str)
			rotone(str);
	}
	write (1, "\n", 1);
	return (0);
}
