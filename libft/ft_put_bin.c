/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:49:05 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/28 11:48:57 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_bin(unsigned long long c, char	*base)
{
	if (c >= ft_strlen(base))
		ft_put_bin(c / ft_strlen(base), base);
	write(1, &base[c % ft_strlen(base)], 1);
}
