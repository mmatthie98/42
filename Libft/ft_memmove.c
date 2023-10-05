

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	i = -1;
	if (dst > src)
	{
		while (len-- > 0)
			dest[len] = source[len];
	}
	else
	{
		while (++i < len)
			dest[i] = source[i];
	}
	return (dst);
}
/*
#include <stdio.h>
int main()
{
	unsigned char src [] = {"ABCDEF"};
	ft_memmove(src+2, src, 2);
	printf("%s\n", src);
}*/
