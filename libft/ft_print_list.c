/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:32:20 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/13 16:34:55 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list	*lst)
{
	while (lst)
	{
		printf("%d\n", *(int *)(lst->content));
		lst = lst->next;
	}
	if (!lst)
		printf("NULL\n");
}
