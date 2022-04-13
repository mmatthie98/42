#include "libft.h"

void	ft_print_int_tab(int	**map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		printf("%d\n", map[i][j]);
		i++;
	}
}
