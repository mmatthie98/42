/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_low_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:04:09 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/27 18:17:44 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_post_low_sort(t_data	*data, t_list	**lst, t_list	**stack_b)
{
	make_int_tab(data);
	*lst = make_a_int(data);
	data->size = ft_lstsize(*lst);
	ft_low_sort(lst, stack_b, data);
}
