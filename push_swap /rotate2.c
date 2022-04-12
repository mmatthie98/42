/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:13:46 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/12 19:20:49 by mmatthie         ###   ########.fr       */
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

void	ft_sort_it(t_list	**lstcopy, t_data *data)
{
	t_list	*tmp;
	t_list	*queue;
	t_list	*head;

	tmp = *lstcopy;
	data->index = 0;
	queue = NULL;
	head = NULL;
	if (*lstcopy)
	{
		printf("test1\n");
		while (*(char *)(*tmp).content < *(char *)(*tmp).next->content)
			tmp = tmp->next;
		if (*(char *)(*tmp).content > *(char *)(*tmp).next->content)
		{
			printf("test2\n");
			queue = tmp;
			head = tmp->next;
			head->next = queue;
		}
		data->index++;
	}
	*lstcopy = queue;
}

int	ft_is_negative(char	**map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (map)
	{
		while (map && map[++i])
		{
			while (map && map[i][++j])
			{
				if (map[i][j] >= 48 && map[i][j] <= 57)
				{
					if (map[i][j + 1] == '-' || map[i][j + 1] == '+')
					{
						return (1);
					}
				}
				else if (map[i][j] == '-')
				{
					while (map[i][j + 1] == ' ')
					{
						j++;
						if (!ft_number(map[i][j]))
							return (1);
					}
				}
			}
		}
	}
	return (0);
}

int	ft_number(char	str)
{
	int		i;

	i = 0;
	if (str >= 0 && str <= 9)
		i++;
	else
		return (1);
	return (0);
}
