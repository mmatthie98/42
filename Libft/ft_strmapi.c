

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>
int main()
{	const char test [] = "coucou";
	int i = 0;
	while(test[i])
	{
		printf("%s", ft_strmapi(test, ));
		i++;
	}
}*/
