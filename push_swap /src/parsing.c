/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:09:27 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/28 11:41:52 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_double(char	**map)
{
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	while (map[i])
	{
		j = i + 1;
		while (map[j])
		{
			if (ft_atoi(map[i]) == ft_atoi(map[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	sort_tab_int(t_data *data)
{
	int	min;
	int	tmp;

	init_data(data);
	while (data->i < (int)data->maplen)
	{
		min = data->i;
		data->j = data->i + 1;
		while (data->j < (int)data->maplen)
		{
			if (*data->tab_copy[data->j] < *data->tab_copy[min])
				min = data->j;
			data->j++;
		}
		if (min != data->i)
		{
			tmp = *data->tab_copy[data->i];
			*data->tab_copy[data->i] = *data->tab_copy[min];
			*data->tab_copy[min] = tmp;
		}
		data->i++;
	}
}

void	switch_index(t_data *data)
{
	int	indicateur;

	indicateur = 0;
	init_data(data);
	while (data->i < (int)data->maplen)
	{
		data->j = 0;
		while (data->j < (int)data->maplen)
		{
			if (indicateur == 0)
			{
				if (*data->tab[data->i] == *data->tab_copy[data->j])
				{
					*data->tab[data->i] = data->j;
					indicateur++;
				}
			}
			data->j++;
		}
		indicateur = 0;
		data->i++;
	}
}

void	ft_post_radix(t_data *data, t_list	**lst, t_list	**stack_b)
{
	make_int_tab(data);
	make_copy_int_tab(data);
	sort_tab_int(data);
	switch_index(data);
	*lst = make_a_int(data);
	data->binary_size = ft_get_binary_size(data);
	ft_binary_move(data, lst, stack_b);
}

int	main(int ac, char	**av)
{
	t_list	*lst;
	t_list	*stack_b;
	t_data	*data;

	stack_b = NULL;
	data = malloc(sizeof(t_data));
	if (ac > 1)
	{
		data->map = split_multiple_param(av, data);
		if (data->map == NULL)
			return (EXIT_FAILURE);
		init_data(data);
		if (!parse(data->map, data))
		{
			if (data->maplen < 6 && ft_map_is_sort(data) == 1)
				ft_post_low_sort(data, &lst, &stack_b);
			if (data->maplen > 5 && ft_map_is_sort(data) == 1)
				ft_post_radix(data, &lst, &stack_b);
		}
	}
	return (0);
}
