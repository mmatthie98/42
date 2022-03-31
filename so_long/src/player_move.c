/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:31:07 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/31 20:25:13 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_up(t_data	*data)
{
	put_player_xpm(data, "./img/lavafloor.xpm");
	data->player_i--;
	put_double_player_xpm(data, "./img/lavafloor.xpm", \
	"./img/sausage_front.xpm");
	data->move++;
}

void	player_move_down(t_data	*data)
{
	put_player_xpm(data, "./img/lavafloor.xpm");
	data->player_i++;
	put_double_player_xpm(data, "./img/lavafloor.xpm", \
	"./img/sausage_front.xpm");
	data->move++;
}

void	player_move_right(t_data	*data)
{
	put_player_xpm(data, "./img/lavafloor.xpm");
	data->player_j++;
	put_double_player_xpm(data, "./img/lavafloor.xpm", \
	"./img/sausage_front.xpm");
	data->move++;
}

void	player_move_left(t_data	*data)
{
	put_player_xpm(data, "./img/lavafloor.xpm");
	data->player_j--;
	put_double_player_xpm(data, "./img/lavafloor.xpm", \
	"./img/sausage_front.xpm");
	data->move++;
}
