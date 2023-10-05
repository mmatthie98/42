/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:54:50 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/06 13:38:48 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(char	*s1, char	*s2, size_t	n)
{
	size_t			i;
	unsigned char	str1;
	unsigned char	str2;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		str1 = (unsigned char)s1[i];
		str2 = (unsigned char)s2[i];
		if (str1 != str2)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen_long(char	*str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free (s1);
	return (str);
}

int	ft_check_ber(char	*filename)
{
	char	*str;
	size_t	sizelen;
	int		i;

	sizelen = ft_strlen(filename);
	i = 0;
	while (filename[i] && filename[i] != '.')
	{
		i++;
		sizelen--;
	}
	if (filename[i] && sizelen == 4)
		str = filename + i;
	else
		return (1);
	if (ft_strncmp(str, ".ber", ft_strlen(str)))
		return (0);
	return (1);
}

void	*ft_calloc( size_t	count, size_t	size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!(ptr))
		return (NULL);
	while (i < count * size)
		*(char *)(ptr + i++) = 0;
	return (ptr);
}
