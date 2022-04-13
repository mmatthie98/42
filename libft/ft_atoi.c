/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:11:39 by mmatthie          #+#    #+#             */
/*   Updated: 2021/10/21 16:11:39 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	neg;
	int	i;

	i = 0;
	neg = 1;
	res = 0;
	/*if (!str)
		exit(2);*/
	while (str[i] >= 7 && str[i] <= 13)
		i++;
	if ((str && (str[i] == '+')) || (str && (str[i] == '-')))
	{
		if (str[i] == '-')
			neg -= 2;
		i++;
	}
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
}
