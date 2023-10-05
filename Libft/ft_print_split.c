

#include "libft.h"

void	ft_print_split(char	**map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
