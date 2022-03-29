/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_border.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:07:20 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/29 19:08:53 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_both_border(char *first, char *last)
{
	int	i;

	i = 0;
	while (first && first[i])
	{
		if (first[i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (last && last[i])
	{
		if (last[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_mid_border(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (1);
		else if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_len(char	**map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_border_map(char	**map)
{
	size_t	i;

	i = ft_strlen_tab(map);
	if (check_len(map))
		return (2);
	if (ft_check_both_border(map[0], map[i - 1]))
		return (3);
	if (ft_check_mid_border(map))
		return (4);
	return (0);
}

int	ft_check_nl(char	*str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if ((str[i] != '1') && (str[i] != 'C') \
		&& (str[i] != 'E') && (str[i] != 'P'))
			return (1);
		return (0);
	}
	return (0);
}
