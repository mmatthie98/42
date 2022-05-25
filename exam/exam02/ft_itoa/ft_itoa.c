#include <stdlib.h>
#include <stdio.h>

static	int	ft_nbsize(int nb)
{
	int	i;

	i = 0;
	if (!nb)
		return(1);
	if (nb < 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int ft_strlen(char	*str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

char	*ft_strdup(char	*s)
{
	char	*str;
	int		i;
	int		len;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s[i] && s[++i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int	nbr)
{
	char	*str;
	int		len;

	if (nbr == -2147483648)
		ft_strdup("-2147483648");
	len = ft_nbsize(nbr);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (nbr == 0 || !nbr)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	str[len] = '\0';
	while (nbr)
	{
		str[--len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}