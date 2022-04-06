/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:37:22 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/06 13:29:07 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_double_xpm(t_data	*data, char	*path1, char	*path2)
{
	data->img = mlx_xpm_file_to_image(data->mlx, path1, \
	&data->img_width, &data->img_height);
	if (!data->img)
	{
		ft_printf("img error\n");
		ft_free_map(data->map);
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->img, ((data->j) * 40), ((data->i) * 40));
	data->img = mlx_xpm_file_to_image(data->mlx, path2, \
	&data->img_width, &data->img_height);
	if (!data->map)
	{
		ft_printf("img error\n");
		ft_free_map(data->map);
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->img, ((data->j) * 40), ((data->i) * 40));
}

void	put_xpm(t_data	*data, char	*path)
{
	data->img = mlx_xpm_file_to_image(data->mlx, path, \
	&data->img_width, &data->img_height);
	if (!data->img)
	{
		ft_printf("img error\n");
		ft_free_map(data->map);
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->img, ((data->j) * 40), ((data->i) * 40));
}

void	start_it(t_data	*data)
{
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, 17, 1L << 2, ft_close_it, data);
	mlx_loop(data->mlx);
}

void	make_content(t_data	*data)
{
	init_struct(data);
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == '1')
				put_double_xpm(data, "./img/lavafloor.xpm", "./img/wall.xpm");
			else if (data->map[data->i][data->j] == 'P')
				put_double_xpm(data, "./img/lavafloor.xpm", \
				"./img/sausage_front.xpm");
			else if (data->map[data->i][data->j] == 'C')
				put_double_xpm(data, "./img/lavafloor.xpm", \
				"./img/sauce_piquante.xpm");
			else if (data->map[data->i][data->j] == 'E')
				put_double_xpm(data, "./img/lavafloor.xpm", "./img/Exit.xpm");
			else if (data->map[data->i][data->j] == '0')
				put_xpm(data, "./img/lavafloor.xpm");
			data->j++;
		}
		data->i++;
	}
	start_it(data);
}

int	main(int ac, char	**av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac == 2 && ft_check_ber(av[1]))
	{
		data->map = parse(av[1], data);
		if (!data->map)
			return (1);
		if (!ft_check_border_map(data) && !ft_check_map_contain(data->map))
		{
			init_struct(data);
			init_player(data);
			get_player_pos(data);
			initialize_map(data);
			print_split(data->map);
			init_win(data);
			make_content(data);
			start_it(data);
		}
		else
			ft_printf("map is not ok.\n");
	}
	else
		ft_printf("Invalid args\n");
	return (0);
}
