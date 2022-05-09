/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_low_sort2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:37 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/09 15:00:15 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_the_3(t_list	**a, t_list	**b, t_data	*data)
{
	if (data->pos == 3)
	{
		ft_rotate(a);
		sa(a);
		ft_pb(a, b);
		ft_low_sort(a, b, data);
		ft_pa(a, b);
	}
}

void	do_small_sort(t_list	**a, t_data	*data)
{
	if (data->second > data->first \
		&& data->second > data->third \
		&& data->third > data->first)
	{
		ft_reverse_rotate(a);
		sa(a);
	}
	if (data->third > data->first \
	&& data->third > data->second \
	&& data->second < data->first)
		sa(a);
}

void	do_small_4(t_list	**a, t_list	**b, t_data	*data)
{
	if (*a)
	{
		if (data->pos_small == 3)
		{
			ft_rotate(a);
			sa(a);
			ft_pb(a, b);
			ft_low_sort(a, b, data);
			ft_pa(a, b);
		}
		if (data->pos_small == 4)
		{
			ft_reverse_rotate(a);
			ft_pb(a, b);
			ft_low_sort(a, b, data);
			ft_pa(a, b);
		}
	}
}
