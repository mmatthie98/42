/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:08:50 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/27 14:45:07 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pb(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (*stack_a)
	{
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	write(1, "pb\n", 3);
}

void	ft_pa(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	if (*stack_b)
	{
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	write (1, "pa\n", 3);
}

void	ft_rotate(t_list	**stack_a)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_a;
	if ((*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		last = ft_lstlast(*stack_a);
		(*stack_a)->next = NULL;
		last->next = *stack_a;
		*stack_a = tmp;
	}
	*stack_a = tmp;
	write (1, "ra\n", 3);
}

void	sa(t_list	**stack_a)
{
	t_list	*tmp;
	t_list	*second;

	tmp = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		second = (*stack_a)->next->next;
		*stack_a = (*stack_a)->next;
		(*stack_a)->next = tmp;
		tmp->next = second;
	}
	write(1, "sa\n", 3);
}

void	ft_reverse_rotate(t_list	**stack_a)
{
	t_list	*last;
	t_list	*tmp;
	t_list	*pre_last;
	int		size;

	size = ft_lstsize(*stack_a);
	last = ft_lstlast(*stack_a);
	tmp = *stack_a;
	pre_last = *stack_a;
	while ((*stack_a) && --size > 1)
		pre_last = pre_last->next;
	last->next = tmp;
	pre_last->next = NULL;
	*stack_a = last;
	write(1, "rra\n", 4);
}
