/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:09:06 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/27 14:26:03 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	small_sort(t_list	**a, t_data	*data)
{
	if (data->size > 2 && (ft_map_is_sort(data)) == 1)
	{
		if (data->first > data->second \
		&& data->first > data->third \
		&& data->second < data->third)
			ft_rotate(a);
		if (data->third < data->first \
		&& data->third < data->second \
		&& data->first > data->second)
		{
			sa(a);
			ft_reverse_rotate(a);
		}
		if (data->second > data->first \
			&& data->second > data->third \
			&& data->third < data->first)
			ft_reverse_rotate(a);
		else
			do_small_sort(a, data);
	}
}

void	ft_sort_4(t_list	**a, t_list	**b, t_data	*data)
{
	if (*a)
	{
		if (data->pos_small == 1)
		{
			ft_pb(a, b);
			ft_low_sort(a, b, data);
			ft_pa(a, b);
		}
		if (data->pos_small == 2)
		{
			sa(a);
			ft_pb(a, b);
			ft_low_sort(a, b, data);
			ft_pa(a, b);
		}
		else
			do_small_4(a, b, data);
	}
}

int	ft_map_is_sort(t_data	*data)
{
	init_data(data);
	while (data->map[data->i])
	{
		data->j = data->i + 1;
		while (data->map[data->j])
		{
			if (ft_atoi(data->map[data->i]) > ft_atoi(data->map[data->j]))
				return (1);
			data->j++;
		}
		data->i++;
	}
	return (0);
}

int	ft_check_sort(t_list	*lst, t_data	*data)
{
	init_data(data);
	while (lst && lst->next)
	{
		if (*lst->content > *lst->next->content)
			return (1);
		else
			lst = lst->next;
	}
	return (0);
}

void	ft_low_sort(t_list	**a, t_list	**b, t_data	*data)
{
	data->size = ft_lstsize(*a);
	if (data->size == 2)
		ft_sort_2(a, data);
	if (data->size == 3)
		ft_sort_3(a, data);
	if (data->size == 4)
		ft_sort_for_4(a, b, data);
	if (data->size == 5)
		sort_for_5(a, b, data);
}
