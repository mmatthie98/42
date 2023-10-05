/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocobongo <cocobongo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:01:12 by mmatthie          #+#    #+#             */
/*   Updated: 2023/10/06 00:11:15 by cocobongo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	make_int_tab(t_data	*data)
{
	size_t		len;

	init_data(data);
	data->tab = malloc(sizeof(int *) * data->maplen + 1);
	if (!data->tab)
		exit(2);
	while (data->map[data->i])
	{
		len = ft_strlen(data->map[data->i]);
		data->tab[data->i] = malloc(sizeof(int) * len + 1);
		if (!data->tab[data->i])
			exit(2);
		data->i++;
	}
	data->i = 0;
	while (data->map[data->i])
	{
		*data->tab[data->i] = ft_atoi(data->map[data->i]);
		data->i++;
	}
}

void	make_copy_int_tab(t_data	*data)
{
	size_t		len;

	init_data(data);
	data->tab_copy = malloc(sizeof(int *) * data->maplen + 1);
	if (!data->tab_copy)
		exit(2);
	while (data->map[data->i])
	{
		len = ft_strlen(data->map[data->i]);
		data->tab_copy[data->i] = malloc(sizeof(int) * len + 1);
		if (!data->tab_copy[data->i])
			exit(2);
		data->i++;
	}
	data->i = 0;
	while (data->map[data->i])
	{
		*data->tab_copy[data->i] = ft_atoi(data->map[data->i]);
		data->i++;
	}
}

int	ft_get_binary_size(t_data	*data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->tab_copy[i])
		i++;
	i -= 1;
	while ((i >> j) != 0)
		j++;
	return (j);
}

void	ft_binary_move(t_data	*data, t_list	**a, t_list	**stack_b)
{
	int		i;
	int		j;
	
	
	init_data(data);
	i = -1;
	while (++i < data->binary_size)
	{
		j = -1;
		if (ft_check_sort(*a, data))
		{
			while (++j < (int)data->maplen)
			{
				if ((*(*a)->content >> i & 1) == 1)
					ft_rotate(a);
				else
					ft_pb(a, stack_b);
			}
		}
		ft_make_it(a, stack_b);
	}
}

void	ft_make_it(t_list	**a, t_list	**stack_b)
{
	while (*stack_b)
		ft_pa(a, stack_b);
}
