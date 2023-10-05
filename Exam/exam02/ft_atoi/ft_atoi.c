#include <stdio.h>

int	ft_atoi(const	char	*str)
{
	int	neg;
	int	res;
	int	i;

	neg = 1;
	res = 0;
	i = 0;
	if (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			neg = -1;
			i++;
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
}

int main()
{
	char	*str;

	str = "123";
	printf("%d\n", ft_atoi(str));
	return (0);
}