
#include "libft.h"

long long	ft_atoll(const char *str)
{
	int			i;
	long long	result;
	int			negative;

	i = 0;
	result = 0;
	negative = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' \
	|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] && ft_is_numeric(str[i]))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * negative);
}
