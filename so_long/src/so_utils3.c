/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:48:17 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/30 11:04:32 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

void	print_split(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	put_double_player_xpm(t_data	*data, char	*path1, char	*path2)
{
	data->img = mlx_xpm_file_to_image(data->mlx, path1, \
	&data->img_width, &data->img_height);
	if (!data->img)
	{
		printf("img error\n");
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->img, ((data->player_j) * 40), ((data->player_i) * 40));
	data->img = mlx_xpm_file_to_image(data->mlx, path2, \
	&data->img_width, &data->img_height);
	if (!data->map)
	{
		printf("img error\n");
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->img, ((data->player_j) * 40), ((data->player_i) * 40));
}

void	put_player_xpm(t_data	*data, char	*path)
{
	data->img = mlx_xpm_file_to_image(data->mlx, path, \
	&data->img_width, &data->img_height);
	if (!data->img)
	{
		printf("img error\n");
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->img, ((data->player_j) * 40), ((data->player_i) * 40));
}

int	checktheline(t_data	*data)
{
	ft_check_nl(data);
	if (data->count_n != data->count_0)
		return (1);
	return (0);
}