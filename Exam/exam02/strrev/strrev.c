#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*str)
{
	char	*s;
	int		i;

	i = -1;
	s = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	while (str[++i])
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}

char	*strrev(char	*str)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

/*
int main()
{
	char	*str;
	
	//str = "123456";
	str = ft_strdup("123456");
	printf("the string before rev is : %s\n", str);
	printf("the string in rev is : %s\n",strrev(str));
	return (0);
}*/