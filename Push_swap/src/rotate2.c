/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:13:46 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/09 14:40:34 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_5(t_list	**a, t_list	**b, t_data	*data)
{
	if (*a)
	{
		if (data->pos == 1)
		{
			ft_pb(a, b);
			ft_low_sort(a, b, data);
			ft_pa(a, b);
		}
		if (data->pos == 2)
		{
			sa(a);
			ft_pb(a, b);
			ft_low_sort(a, b, data);
			ft_pa(a, b);
		}
		if (data->pos == 3)
			do_the_3(a, b, data);
		else
			found_the_place(a, b, data);
	}
}

void	ft_swap_tab(char	*a, char	*b)
{
	char	*x;
	char	*y;

	y = NULL;
	x = ft_strcpy(y, a);
	*a = *b;
	*b = *x;
}

void	ft_sort_it(t_data *data)
{
	init_data(data);
	while (data->map[data->i])
	{
		while (data->map[data->j])
		{
			data->j++;
			if (ft_atoi(data->map[data->j]) < ft_atoi(data->map[data->i]))
				ft_swap_tab(data->map[data->i], data->map[data->j]);
			data->i++;
		}
	}
}

int	ft_is_neg(char	**map, t_data	*data)
{
	init_data(data);
	if (map)
	{
		while (map && map[data->i])
		{
			while (map && map[data->i][data->j])
			{
				if (map[data->i][data->j] >= '0'\
				&& map[data->i][data->j] <= '9')
				{
					if (map[data->i][data->j + 1] == '-'\
					|| map[data->i][data->j + 1] == '+')
						return (1);
				}
				data->j++;
			}
			data->i++;
		}
	}
	return (0);
}
