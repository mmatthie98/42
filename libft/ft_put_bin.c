/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:49:05 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/08 18:11:19 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	ft_putsize(unsigned long long c, char	*base)
{
	int	i;

	i = 0;
	ft_put_bin(c, base);
	if (c == 0)
		return(1);
	while (c)
	{
		c /= ft_strlen(base);
		i++;
	}
	return (i);
}*/

void	ft_put_bin(unsigned long long	c, char	*base)
{
	if (c >= ft_strlen(base))
		ft_put_bin(c / ft_strlen(base), base);
	write(1, &base[c % ft_strlen(base)], 1);
}

int main ()
{
	unsigned long long	i;

	i = 100000000042;
	ft_put_bin(i, "01");
	write(1, "\n", 1);
	return (0);

}
