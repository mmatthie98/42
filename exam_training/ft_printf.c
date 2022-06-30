#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_putstr(char	*str)
{
	while (str)
		return (write(1, str, ft_strlen(str)));
	return (write (1, "(null)", 6));
}

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnb(int nb)
{
	if (nb == -2147483648)
	{
		write (1 , "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar ('-');
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

void	ft_puthex(unsigned long long nb)
{
	if (nb > 15)
	{
		ft_puthex(nb / 16);
		ft_puthex(nb % 16);
	}
	else if (nb > 9 && nb < 17)
		ft_putchar(nb + 87);
	else
		ft_putchar(nb + 48);
}

void	ft_check_var(va_list ap, char c)
{
	if (c == 's')
		ft_putstr(va_arg(ap, char *));
	else if (c == 'd')
		ft_putnb(va_arg(ap, int));
	else if (c == 'x')
		ft_puthex(va_arg(ap, unsigned long long));
}

int	ft_printf(const char	*str, ...)
{
	va_list	ap;
	int	i;
	va_start(ap, str);

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_check_var(ap, str[++i]);
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return(0);
}

int main()
{
	unsigned int v = 0;
	ft_printf("%x\n", v);
	printf("%x\n", v);
	ft_printf("aloura %s", "mon reuf\n");
	ft_printf("aloura %s\n", NULL);
	ft_printf("ecole %d\n", 42);
	ft_printf("le d fonctionne bien : %d\n", 0);
	ft_printf("for x : %x\n", 42);
	ft_printf("for x : %x\n", 142);
	ft_printf("int min : %d\n", -2147483648);
	ft_printf("int max : %d\n", 2147483647);
	ft_printf("zero in : %d\n", 0);
	ft_printf("neg in : %d\n", -42);
	printf("___real printf___\n");
	printf("aloura %s", "mon reuf\n");
	printf("aloura %s\n", NULL);
	printf("ecole %d\n", 42);
	printf("le d fonctionne bien : %d\n", 0);
	printf("for x : %x\n", 42);
	printf("for x : %x\n", 142);
	int x = -2147483648;
	int y =	2147483647;
	printf("int min : %d\n", x);
	printf("int max : %d\n", y);
	printf("zero in : %d\n", 0);
	printf("neg in : %d\n", -42);
	return (0);
}
