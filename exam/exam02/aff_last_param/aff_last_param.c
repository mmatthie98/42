#include <unistd.h>

int main(int ac, char	**av)
{
	int	i;
	int	j;
	char	*str;

	i = 1;
	j = 0;
	if (ac > 1)
	{
		while (i < ac - 1)
			i++;
		str = av[i];
		while (str[j])
		{
			write(1, &str[j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}