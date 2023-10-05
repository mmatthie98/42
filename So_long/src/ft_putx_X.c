/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:16:22 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/06 13:43:58 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putbase(unsigned long long nb, char	*base)
{
	if (nb >= ft_strlen(base))
		ft_putbase(nb / ft_strlen(base), base);
	write(1, &base[nb % ft_strlen(base)], 1);
}

int	ft_putsize(unsigned long long nb, char *base, void *pt)
{
	int	i;

	if (pt && nb == 0)
		nb = (unsigned long long)pt;
	i = 0;
	ft_putbase(nb, base);
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= ft_strlen(base);
		i++;
	}
	return (i);
}
