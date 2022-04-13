/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:01:12 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/13 18:38:40 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_get_binary_size(t_data	*data, int	nb)
{
	data->binary_size = 0;
	while (nb / 2)
	{
		nb /= 2;
		data->binary_size++;
	}
}
