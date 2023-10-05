/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:16:25 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/31 20:25:13 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_win(t_data	*data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_free_map(data->map);
	exit (0);
}

int	ft_close_it(t_data	*data)
{
	ft_close_win(data);
	return (0);
}

int	key_hook(int keycode, t_data	*data)
{
	if (keycode == ESC_KEY)
	{
		ft_close_win(data);
		return (1);
	}
	if (keycode == Z)
		ft_move_up(data);
	if (keycode == S)
		ft_move_down(data);
	if (keycode == D)
		ft_move_right(data);
	if (keycode == Q)
		ft_move_left(data);
	return (0);
}
