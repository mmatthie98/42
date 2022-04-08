/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:13:46 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/08 10:20:20 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_5(t_list	**a, t_list	**b, t_data	*data)
{
	if (*a)
	{
		if (data->pos == 1)
		{
			ft_PB(a, b);
			ft_sort_for_4(a, b, data);
			ft_PA(a, b);
		}
		if (data->pos == 2)
		{
			SA(a);
			ft_PB(a, b);
			ft_sort_for_4(a, b, data);
			ft_PA(a, b);
		}
		if (data->pos == 3)
		{
			ft_rotate(a);
			SA(a);
			ft_PB(a, b);
			ft_sort_for_4(a, b, data);
			ft_PA(a, b);
		}
		if (data->pos == 4)
		{
			ft_reverse_rotate(a);
			ft_reverse_rotate(a);
			ft_PB(a, b);
			ft_sort_for_4(a, b, data);
			ft_PA(a, b);
		}
		if (data->pos == 5)
		{
			ft_reverse_rotate(a);
			ft_PB(a, b);
			ft_sort_for_4(a, b, data);
			ft_PA(a, b);
		}
	}
}

void	ft_sort_it(t_list	**a, t_data *data)
{
	t_list	*tmp;
	t_list	*second;

	tmp = *a;
	while (tmp)
	{
		while (!ft_is_sort(a, data))
		{
			if (ft_atoi(tmp->content) > ft_atoi(tmp->next->content))
			{
				second = tmp->next->next;
				(*a) = (*a)->next;
				(*a)->next = tmp;
				tmp->next = second;
			}
			else
				tmp = tmp->next;
		}
	}
}

/*int	ft_is_negative(char	**map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '-')
			{
				if (map[i][j + 1] == '')
			}
		}
	}
}*/
