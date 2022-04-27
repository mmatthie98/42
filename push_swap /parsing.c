/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:09:27 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/27 18:25:13 by mmatthie         ###   ########.fr       */
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
				if (is_max_or_min(map) == 1)
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


t_list	*make_a_int(t_data *data)
{
	t_list *a;

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

void	sort_tab_int(t_data *data)
{
	int min;
	int tmp;

	init_data(data);
	while (data->i < (int)data->maplen)
	{
		min = data->i;
		data->j = data->i + 1;
		while(data->j < (int)data->maplen)
		{
			if(*data->tab_copy[data->j] < *data->tab_copy[min])
				min = data->j;
			data->j++;
		}
		if (min != data->i)
		{
			tmp = *data->tab_copy[data->i];
			*data->tab_copy[data->i] = *data->tab_copy[min];
			*data->tab_copy[min] = tmp;
		}
		data->i++;
	}
	data->max_value = *data->tab_copy[data->maplen - 1];
}

void	switch_index(t_data *data)
{
	int indicateur;

	indicateur = 0;
	init_data(data);
	while(data->i < (int)data->maplen)
	{
		data->j = 0;
		while (data->j < (int)data->maplen)
		{
			if (indicateur == 0)
			{
				if (*data->tab[data->i] == *data->tab_copy[data->j])
				{
					*data->tab[data->i] = data->j;
					indicateur++;
				}
			}
			data->j++;
		}
		indicateur = 0;
		data->i++;
	}
}


void	ft_post_radix(t_data *data, t_list	**lst, t_list	**stack_b)
{
	printf("big_sort\n");
	make_int_tab(data);
	make_copy_int_tab(data);
	sort_tab_int(data);
	switch_index(data);
	*lst = make_a_int(data);
	ft_get_binary_size(data->max_value);
	ft_binary_move(data, lst, stack_b);
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
		data->map = split_multiple_param(av, data);
		if (data->map == NULL)
			return (EXIT_FAILURE);
		init_data(data);
		if (!parse(data->map))
		{
			if (data->maplen < 6 && ft_map_is_sort(data) == 1)
				ft_post_low_sort(data, &lst, &stack_b);
			if (data->maplen > 5 && ft_map_is_sort(data) == 1)
				ft_post_radix(data, &lst, &stack_b);
			//ft_print_list(lst);
			//system("leaks push_swap");
		}
	}
	return (0);
}
