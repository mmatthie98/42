
#include <unistd.h>

void	ft_swap_char(char	*a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

void		search_and_replace(char	*str, char	*c, char *d)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == *c)
			ft_swap_char(c, d);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int main(int	ac, char	**av)
{
	char	*c;
	char	*d;
	char			*str;
	int				i;

	i = 0;
	if (ac == 4)
	{
		str = av[1];
		c = (char *)av[2];
		d = (char *)av[3];
		search_and_replace(str, c, d);	
	}
	write(1, "\n", 1);
	return (0);
}