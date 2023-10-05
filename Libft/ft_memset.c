

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int main()
{
	unsigned char test [] = {'b', 'w', 'f', 'q', 'p', 'l'};
	ft_memset(test, 5, 6);

	int i = 0;
	while(i < 6)
	{
		printf("%d\n", test[i]);
		i++;
	}
}*/
