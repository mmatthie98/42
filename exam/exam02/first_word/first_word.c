#include <unistd.h>

int main(int ac, char	**av)
{
	int i;
	int	indicate;
	char	*str;

	i = 0;
	indicate = 0;
	if (ac == 2)
	{
		str = av[1];
		if (indicate == 0)
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			{
				write(1, &str[i], 1);
				indicate++;
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}