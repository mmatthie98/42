#include "ft_printf.h"

int	ft_putc(int c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_puts(char	*str)
{
	while (str)
		return (write(1, str, ft_strlen(str)));
	return (write(1, "(null)", 6));
}

void	ft_puthex(unsigned long long nb, char	*base)
{
	if (nb >= ft_strlen(base))
		ft_puthex(nb / ft_strlen(base), base);
	write(1, &base[nb % ft_strlen(base)], 1);
}

void	ft_putnb(int nb)
{
	if (nb == -2147483648)
	{
		ft_putc('-');
		ft_putc('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putc('-');
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putc(nb + 48);
		return ;
	}
	else
		ft_putnb(nb / 10);
	ft_putc(nb % 10 + 48);
}

int	ft_puti(int nb)
{
	int	i;

	i = ft_putsize_nb(nb);
	ft_putnb(nb);
	return (i);
}

int	ft_putsize_nb(int nb)
{
	size_t	i;

	i = 0;
	if (nb == -2147483648)
		return (11);
	if (nb <= 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_putsize(unsigned long long nb, char	*base)
{
	int	i;

	i = 0;
	ft_puthex(nb, base);
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= ft_strlen(base);
		i++;
	}
	return (i);
}

int	ft_check_var(va_list	ap, int c)
{
	if (c == 'c')
		return (ft_putc(va_arg(ap, int)));
	else if (c == 's')
		return (ft_puts(va_arg(ap, char	*)));
	else if (c == '%')
		return (ft_putc('%'));
	else if (c == 'x')
		return (ft_putsize((unsigned long long)va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putsize((unsigned long long)va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (c == 'i' || c == 'd')
		return (ft_puti(va_arg(ap, int)));
	return (1);
}


int	ft_printf(const char	*str, ...)
{
	va_list	ap;
	int		i;
	int		j;

	va_start(ap, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
			j += ft_check_var(ap, str[++i]);
		else
			j += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (j);
}


