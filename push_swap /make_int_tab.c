/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:01:12 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/26 12:44:56 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	make_int_tab(t_data	*data)
{
	size_t		len;
	init_data(data);
	data->tab = malloc(sizeof(int *) * data->maplen + 1);
	if (!data->tab)
		exit(2);
	while (data->map[data->i])
	{
		len = ft_strlen(data->map[data->i]);
		data->tab[data->i] = malloc(sizeof(int) * len + 1);
		if (!data->tab[data->i])
			exit(2);
		data->i++;
	}
	data->i = 0;
	while (data->map[data->i])
	{
		*data->tab[data->i] = ft_atoi(data->map[data->i]);
		data->i++;
	}
}

void	make_copy_int_tab(t_data	*data)
{
	size_t		len;
	init_data(data);
	data->tab_copy = malloc(sizeof(int *) * data->maplen + 1);
	if (!data->tab_copy)
		exit(2);
	while (data->map[data->i])
	{
		len = ft_strlen(data->map[data->i]);
		data->tab_copy[data->i] = malloc(sizeof(int) * len + 1);
		if (!data->tab_copy[data->i])
			exit(2);
		data->i++;
	}
	data->i = 0;
	while (data->map[data->i])
	{
		*data->tab_copy[data->i] = ft_atoi(data->map[data->i]);
		data->i++;
	}
}

void	ft_get_binary_size(t_data	*data, int	nb)
{
	data->binary_size = 0;
	while (nb / 2)
	{
		nb /= 2;
		data->binary_size++;
	}
}

void	ft_binary_move(t_data	*data, t_list	**a, t_list	**stack_b)
{
	int		i;
	int		j;
	t_list	*tmp;
	t_list	*b;

	j = 0;
	i = -1;
	tmp = *a;
	b = *stack_b;
	data->size = ft_lstsize(*a);
	printf("list before bin_move : \n");
	printf("binary_size : %d\n", data->binary_size);
	ft_print_list(*a);
	while (++i < data->binary_size)
	{
		printf("int i : %d\n", i);
		j = -1;
		while (++j < data->size)
		{
			printf("int j : %d\n", j);
			printf("content -> %d\n", *(int *)(*a)->content);
			if ((*(int *)(*a)->content >> i & 1))
				ft_reverse_rotate(a);
			else
				ft_PB(a, stack_b);
		}
		while (*stack_b)
			ft_PA(a, stack_b);
		ft_print_list(*a);
	}
	ft_print_list(*a);
}

void	ft_make_it(t_list	*a, t_list	*stack_b)
{
	while (stack_b)
		ft_PA(&a, &stack_b);
}
