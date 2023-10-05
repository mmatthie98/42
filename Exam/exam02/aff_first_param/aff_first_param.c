#include <unistd.h>

int main(int	ac, char	**av)
{
	int	i;
	char	*str;

	i = 0;
	if (ac > 1)
	{
		str = av[1];
		while (str && str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
