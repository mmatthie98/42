/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:09:27 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/08 17:20:57 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_double(char	**map)
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

int parse(char	**map)
{
	int	i;
	int		j;

	i = 0;
	j = 0;
	if (map && map[i])
	{
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				if (is_max_or_min(map))
					quit_with_message(1);
				if (ft_isvalid(map[i]))
					quit_with_message(2);
				if (check_double(map))
					quit_with_message(3);
				j++;
			}
			i++;
		}
	}
	return (0);
}

char	**split_multiple_param(char **tab)
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
	return (map);
}

t_list	*make_a(char	**map)
{
	int	i;
	t_list *a;

	i = 0;
	a = ft_lstnew(map[i]);
	if (map && map[i])
	{
		while (map[++i])
			ft_lstadd_back(&a, ft_lstnew(map[i]));
	}
	return (a);
}


int main(int ac, char   **av)
{
	t_list	*lst;
	t_list	*stack_b;
	t_data	*data;

	stack_b = NULL;
	data = malloc(sizeof(t_data));
	if (ac > 1)
	{
		data->map = split_multiple_param(av);
		if (data->map == NULL)
			return (EXIT_FAILURE);
		if (!parse(data->map))
		{
			lst = make_a(data->map);
			data->size = ft_lstsize(lst);
			if (data->size < 6 && ft_is_sort(&lst, data))
			{
				ft_low_sort(&lst, &stack_b, data);
			}
			if (data->size > 5 && ft_is_sort(&lst, data))
				ft_sort_it(&lst, data);
			ft_print_list(lst);
		}
	}
	return (0);
}
