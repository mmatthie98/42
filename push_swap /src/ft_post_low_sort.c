/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_low_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:04:09 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/28 11:21:52 by mmatthie         ###   ########.fr       */
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

t_list	*make_a(char	**map)
{
	int		i;
	t_list	*a;

	i = 0;
	a = ft_lstnew(map[i]);
	if (map && map[i])
	{
		while (map[++i])
			ft_lstadd_back(&a, ft_lstnew(map[i]));
	}
	return (a);
}

int	parse(char	**map, t_data	*data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (map && map[i])
	{
		if (is_max_or_min(map) == 1)
			quit_with_message(1);
		if (check_double(map))
			quit_with_message(3);
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				if (ft_isvalid(map[i]) || ft_is_neg(&map[i], data))
					quit_with_message(2);
				j++;
			}
			i++;
		}
	}
	return (0);
}

char	**split_multiple_param(char **tab, t_data	*data)
{
	char	str[100000];
	char	**map;
	int		i;
	int		y;
	int		z;

	i = 0;
	y = -1;
	z = -1;
	map = NULL;
	if (tab == NULL)
		return (NULL);
	while (tab[++i])
	{
		while (tab[i][++y])
			str[++z] = tab[i][y];
		str[++z] = ' ';
		y = -1;
	}
	map = ft_split(str, ' ');
	if (!map)
		return (NULL);
	data->maplen = ft_strlentab(map);
	return (map);
}

t_list	*make_a_int(t_data *data)
{
	t_list	*a;

	init_data(data);
	a = ft_lstnew(data->tab[data->i]);
	data->i = 1;
	if (data->tab && data->tab[data->i])
	{
		while (data->i < (int)data->maplen)
		{
			ft_lstadd_back(&a, ft_lstnew(data->tab[data->i]));
			data->i++;
		}
	}
	return (a);
}
