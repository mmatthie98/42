/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:07:53 by mmatthie          #+#    #+#             */
/*   Updated: 2021/06/10 19:08:36 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strcpy(char	*dest,	char	*src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
