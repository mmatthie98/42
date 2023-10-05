/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_border.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:07:20 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/31 20:25:33 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_check_mid_border(char	**map, t_data	*data)
{
	int	i;

	i = 0;
	data->count_0 = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (1);
		else if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		data->count_0++;
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

int	ft_check_border_map(t_data	*data)
{
	size_t	i;

	i = ft_strlen_tab(data->map);
	if (check_len(data->map))
		return (2);
	if (ft_check_both_border(data->map[0], data->map[i - 1]))
		return (3);
	if (ft_check_mid_border(data->map, data))
		return (4);
	return (0);
}
