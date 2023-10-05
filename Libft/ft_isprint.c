
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	else
		return (0);
}
/*
#include<stdio.h>
int main()
{
	printf("%d", ft_isprint(0));
	printf("\n");
	printf("%d", isprint(0));
}*/
