void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnb(int nb)
{
	if (nb > 9)
	{
		ft_putnb(nb / 10);
		ft_putnb(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}
