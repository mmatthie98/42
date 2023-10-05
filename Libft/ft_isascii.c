
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 & c <= 127)
		return (1);
	else
		return (0);
}
/*
#include<stdio.h>
int main()
{
	printf("%d", ft_isascii(110));
	printf("\n");
	printf("%d", isascii(110));
}*/
