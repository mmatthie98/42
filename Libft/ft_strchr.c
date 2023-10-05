

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) s;
	if ((unsigned char) c == 0)
		return ((char *)s + ft_strlen(s));
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return (str + i);
		i++;
	}
	return (NULL);
}
/*
#include<stdio.h>
int main()
{
	char str[] = "bonsoir";
	printf("%s", ft_strchr(str, 'n'));
}*/
