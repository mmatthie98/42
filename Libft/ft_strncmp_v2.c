

#include "libft.h"

int	ft_strncmp_v2(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	src;
	unsigned char	dest;

	i = 0;
	if (!n)
		return (n);
	src = (unsigned char)s1[i];
	dest = (unsigned char)s2[i];
	while ((src && dest) && (i < n))
	{
		src = (unsigned char)s1[i];
		dest = (unsigned char)s2[i];
		if (src != dest)
			return (src - dest);
		i++;
	}
	return (src - dest);
}
