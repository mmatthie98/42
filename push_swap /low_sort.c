/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:09:06 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/06 14:44:50 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	small_sort(t_list	**a, t_data	*data)
{
	if (data->size > 2)
	{
		if (data->first > data->second \
		&& data->first > data->third
		&& data->second < data->third)
			ft_rotate(a);
		if (data->third < data->first \
		&& data->third < data->second \
		&& data->first > data->second)
		{
			SA(a);
			ft_reverse_rotate(a);
		}
		if (data->second > data->first
			&& data->second > data->third \
			&& data->third < data->first)
			ft_reverse_rotate(a);
		if (data->second > data->first
			&& data->second > data->third \
			&& data->third > data->first)
		{
			ft_reverse_rotate(a);
			SA(a);
		}
		if (data->third > data->first \
		&& data->third > data->second \
		&& data->second < data->first)
			SA(a);
	}
}

void	ft_sort_4(t_list	**a, t_list	**b, t_data	*data)
{
	if ((*a)->next)
	{
		if (data->pos == 1)
		{
			ft_PB(a, b);
			small_sort(a, data);
			ft_PA(a, b);
			ft_rotate(a);
		}
		if (data->pos == 2)
		{
			SA(a);
			ft_PB(a, b);
			small_sort(a, data);
			ft_PA(a, b);
			ft_rotate(a);
		}
		if (data->pos == 3)
		{
			ft_rotate(a);
			SA(a);
			ft_PB(a, b);
			small_sort(a, data);
			ft_PA(a, b);
			ft_rotate(a);
		}
		if (data->pos == 4)
		{
			ft_reverse_rotate(a);
			ft_PB(a, b);
			small_sort(a, data);
			ft_PA(a, b);
			ft_rotate(a);
		}
	}
}

int		ft_is_sort(t_list	**a, t_data	*data)
{
	t_list	*tmp;

	tmp = *a;
	if (data->size > 1)
	{
		while (tmp->next)
		{
			if (ft_atoi(tmp->content) > ft_atoi(tmp->next->content))
				return (1);
			tmp = tmp->next;
		}
	}
	if (data->size < 2)
		quit_with_message(5);
	return (0);
}

void	ft_low_sort(t_list	**a,t_list	**b, t_data	*data)
{
	if (data->size == 2)
		ft_sort_2(a, data);
	if (data->size == 3)
		ft_sort_3(a, data);
	if (data->size == 4)
		ft_sort_for_4(a, b, data);
	if (data->size == 5)
		sort_for_5(a, b, data);
}
