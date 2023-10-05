#include <unistd.h>

void	ft_repeat_alpha(char	c)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	if (c >= 65 && c <= 90)
	{
		k = c - 64;
		while (k > 0)
		{
			write(1, &c, 1);
			k--;
		}
	}
	else if (c >= 97 && c <= 122)
	{
		k = c - 96;
		while (k > 0)
		{
			write(1, &c, 1);
			k--;
		}
	}
}

int main(int ac, char	**av)
{
	int	i;
	char	*str;

	i = 0;
	if (ac == 2)
	{
		str = av[1];
		while (str && str[i])
		{
			if (str[i] >= 65 && str[i] <= 90)
				ft_repeat_alpha(str[i]);
			else if (str[i] >= 97 && str[i] <= 122)
				ft_repeat_alpha(str[i]);
			else
				write (1, &str[i], 1);
			i++;
		}
	}
}
