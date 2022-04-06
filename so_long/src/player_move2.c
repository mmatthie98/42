/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:33:05 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/06 13:28:17 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_left(t_data	*data)
{
	data->map[data->player_i][data->player_j] = '0';
	if (data->map[data->player_i][data->player_j - 1] != '1')
	{
		if (data->map[data->player_i][data->player_j - 1] == 'E' \
		&& data->consummable == 0)
		{
			player_move_left(data);
			ft_printf("nb of key used: %d\n", data->move);
			ft_printf("Bien joué ! Tu es une vrai merguez !\n");
			ft_free_map(data->map);
			exit(EXIT_SUCCESS);
		}
		else if (data->map[data->player_i][data->player_j - 1] == 'C')
		{
			player_move_left(data);
			data->consummable--;
		}
		else if (data->map[data->player_i][data->player_j - 1] == '0')
			player_move_left(data);
		ft_printf("nb of key use: %d\n", data->move);
	}
	else
		ft_printf("care, it's a wall!\n");
}

void	ft_move_down(t_data	*data)
{
	data->map[data->player_i][data->player_j] = '0';
	if (data->map[data->player_i + 1][data->player_j] != '1')
	{
		if (data->map[data->player_i + 1][data->player_j] == 'E' \
		&& data->consummable == 0)
		{
			player_move_down(data);
			ft_printf("nb of key used: %d\n", data->move);
			ft_printf("Bien joué ! Tu es une vrai merguez !\n");
			ft_free_map(data->map);
			exit(EXIT_SUCCESS);
		}
		else if (data->map[data->player_i + 1][data->player_j] == 'C')
		{
			player_move_down(data);
			data->consummable--;
		}
		else if (data->map[data->player_i + 1][data->player_j] == '0')
			player_move_down(data);
		ft_printf("nb of key use: %d\n", data->move);
	}
	else
		ft_printf("care, it's a wall!\n");
}

void	ft_move_right(t_data	*data)
{
	data->map[data->player_i][data->player_j] = '0';
	if (data->map[data->player_i][data->player_j + 1] != '1')
	{
		if (data->map[data->player_i][data->player_j + 1] == 'E' \
		&& data->consummable == 0)
		{
			player_move_right(data);
			ft_printf("nb of key used: %d\n", data->move);
			ft_printf("Bien joué ! Tu es une vrai merguez !\n");
			ft_free_map(data->map);
			exit(EXIT_SUCCESS);
		}
		else if (data->map[data->player_i][data->player_j + 1] == 'C')
		{
			player_move_right(data);
			data->consummable--;
		}
		else if (data->map[data->player_i][data->player_j + 1] == '0')
			player_move_right(data);
		ft_printf("nb of key use: %d\n", data->move);
	}
	else
		ft_printf("care, it's a wall!\n");
}

void	ft_move_up(t_data	*data)
{
	data->map[data->player_i][data->player_j] = '0';
	if (data->map[data->player_i - 1][data->player_j] != '1')
	{
		if (data->map[data->player_i - 1][data->player_j] == 'E' \
		&& data->consummable == 0)
		{
			player_move_up(data);
			ft_printf("nb of key used: %d\n", data->move);
			ft_printf("Bien joué ! Tu es une vrai merguez !\n");
			ft_free_map(data->map);
			exit(EXIT_SUCCESS);
		}
		else if (data->map[data->player_i - 1][data->player_j] == 'C')
		{
			player_move_up(data);
			data->consummable--;
		}
		else if (data->map[data->player_i - 1][data->player_j] == '0')
			player_move_up(data);
		ft_printf("nb of key used: %d\n", data->move);
	}
	else
		ft_printf("care, it's a wall!\n");
}
