/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_contain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:12:46 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/31 20:25:13 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_consumable(char	**map)
{
	size_t	i;
	size_t	j;
	int		consumable;

	consumable = 0;
	j = 0;
	i = -1;
	while (map[++i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				consumable++;
			j++;
		}
		j = 0;
	}
	if (consumable < 1)
		return (1);
	return (0);
}

int	ft_check_exit(char	**map)
{
	size_t	i;
	size_t	j;
	int		exit;

	exit = 0;
	j = 0;
	i = -1;
	while (map[++i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		j = 0;
	}
	if (exit != 1)
		return (1);
	return (0);
}

int	ft_check_player(char	**map)
{
	int		i;
	int		j;
	int		player;

	player = 0;
	j = 0;
	i = -1;
	while (map[++i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		j = 0;
	}
	if (player != 1)
		return (1);
	return (0);
}

int	ft_check_ascii(char	**map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		while (map[i][j])
		{
			if ((map[i][j] >= 32) && (map[i][j] <= 47))
				return (1);
			if ((map[i][j] >= 50) && (map[i][j] <= 66))
				return (2);
			if (map[i][j] == 68)
				return (3);
			if ((map[i][j] >= 70) && (map[i][j] <= 79))
				return (4);
			if ((map[i][j] >= 81) && (map[i][j] <= 127))
				return (5);
			j++;
		}
		j = 0;
	}
	return (0);
}

int	ft_check_map_contain(char	**map)
{
	if (ft_check_player(map))
		return (2);
	if (ft_check_exit(map))
		return (3);
	if (ft_check_consumable(map))
		return (4);
	if (ft_check_ascii(map))
		return (1);
	return (0);
}
