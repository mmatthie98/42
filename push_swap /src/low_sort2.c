/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:38:27 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/28 11:20:27 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_2(t_list	**a, t_data	*data)
{
	init_struct(data, a);
	sa(a);
}

void	ft_sort_3(t_list	**a, t_data	*data)
{
	data->size = ft_lstsize(*a);
	init_struct(data, a);
	small_sort(a, data);
}

void	ft_sort_for_4(t_list	**a, t_list	**b, t_data	*data)
{
	init_struct(data, a);
	ft_get_low(data);
	ft_sort_4(a, b, data);
}

void	sort_for_5(t_list	**a, t_list	**b, t_data	*data)
{
	init_struct(data, a);
	ft_get_low_5(data);
	ft_sort_5(a, b, data);
}

void	found_the_place(t_list	**a, t_list	**b, t_data	*data)
{
	if (*a)
	{
		if (data->pos == 4)
		{
			ft_reverse_rotate(a);
			ft_reverse_rotate(a);
			ft_pb(a, b);
			ft_low_sort(a, b, data);
			ft_pa(a, b);
		}
		if (data->pos == 5)
		{
			ft_reverse_rotate(a);
			ft_pb(a, b);
			ft_low_sort(a, b, data);
			ft_pa(a, b);
		}
	}
}
