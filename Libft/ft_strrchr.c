

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if ((char)c == str[i])
			return (&str[i]);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char s[] = "tripouille";
	//char s2[] = "ltripouiel";
	printf("%s", ft_strrchr(s, 't' + 256));
}*/
