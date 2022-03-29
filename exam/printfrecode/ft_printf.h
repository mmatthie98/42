#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char	*str, ...);
int	ft_check_var(va_list	ap, int c);
void	ft_puthex(unsigned long long nb, char	*base);
int	ft_putsize(unsigned long long nb, char	*base);
int	ft_putsize_nb(int nb);
#endif
