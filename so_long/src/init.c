/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:15:24 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/06 13:26:29 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_data	*data)
{
	data->i = 0;
	data->j = 0;
}

void	init_player(t_data	*data)
{
	data->player_i = 0;
	data->player_j = 0;
	data->consummable = 0;
	data->move = 0;
}

int	get_player_pos(t_data	*data)
{
	init_struct(data);
	init_player(data);
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == 'P')
			{
				data->player_i = data->i;
				data->player_j = data->j;
			}
			if (data->map[data->i][data->j] == 'C')
				data->consummable++;
			data->j++;
		}
		data->i++;
	}
	return (0);
}

void	init_win(t_data	*data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		write(1, "error, win don't init.\n", 23);
		exit (0);
	}
	data->mlx_win = mlx_new_window(data->mlx, data->line_lenght * 40, \
	data->col_lenght * 40, "So_long");
}

void	initialize_map(t_data	*data)
{
	data->col_lenght = ft_strlen_tab(data->map);
	data->line_lenght = ft_strlen(data->map[0]);
}
