#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return(i);
	while (str && str[i])
		i++;
	return (i);
}

void	ft_putbase(unsigned int	nb)
{
	if (nb > 15)
	{
		ft_putbase(nb / 16);
		ft_putbase(nb % 16);
	}
	else if (nb > 9 && nb < 17)
		ft_putchar(nb + 87);
	else
		ft_putchar(nb + 48);
}


void ft_putnb(int nb)
{
	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnb(nb / 10);
		ft_putnb(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	write(1, str, ft_strlen(str));
}

void	check_arg(char	arg, va_list	ap)
{
	int	i;

	i = 0;
	if (arg == 'd')
		ft_putnb(va_arg(ap, int));
	else if (arg == 's')
		ft_putstr(va_arg(ap, char *));
	else if (arg == 'x')
		ft_putbase(va_arg(ap, unsigned long long));
}



void	printfmgl(char	*str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	while (str && str[i])
	{
		if (str[i] == '%')
			check_arg(str[++i], ap);
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
}

int	main()
{
	int i = INT_MIN;
	int	j = INT_MAX;

	printfmgl("%s\n", NULL);
	printf("%s\n", NULL);
	printfmgl("%d\n", 1);
	printf("%d\n", 1);
	printfmgl("%x\n", 42);
	printf("%x\n", 42);
	printfmgl("%d\n", -1);
	printf("%d\n", -1);
	printfmgl("%d\n", j);
	printf("%d\n", j);
	printfmgl("%d\n", i);
	printf("%d\n", i);
	printfmgl("coucou ici il n'y a pas d'args\n");
	printf("coucou ici il n'y a pas d'args\n");
	return(0);
}