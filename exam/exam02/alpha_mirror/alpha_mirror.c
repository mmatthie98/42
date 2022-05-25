#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int i;
	char	*str;

	i = 0;
	if (ac == 2)
	{
		str = av[1];
		while (str[i] != '\0')
		{
			if (str[i] >= 65 && str[i] <= 90)
				str[i] = 90 - (str[i] - 65);
			else if (str[i] >= 97 && str[i] <= 122)
				str[i] = 122 - (str[i] - 97);
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}