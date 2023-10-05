

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (!n)
		return (n);
	while ((s1[i] && s2[i]) && (i < n))
	{
		if (s1[i + 1] && !s2[i + 1] && s1[i + 1] != '=')
			return (1);
		if (s1[i] == '=' && !s2[i])
			return (0);
		else if (s1[i] == '=' && s2[i])
			return (1);
		else if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
