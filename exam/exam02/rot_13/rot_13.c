#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char	**av)
{
	char	*str;
	int		i;

	i = 0;
	if (ac == 2)
	{
		str = av[1];
		while (str && str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'M')
				ft_putchar(str[i] += 13);
			else if (str[i] >= 'N' && str[i] <= 'Z')
				ft_putchar(str[i] -= 13);
			else if (str[i] >= 'a' && str[i] <= 'm')
				ft_putchar(str[i] += 13);
			else if (str[i] >= 'n' && str[i] <= 'z')
				ft_putchar(str[i] -= 13);
			i++;
		}
	}
	return (0);
}