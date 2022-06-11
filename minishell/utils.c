/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:12:32 by tbrandt           #+#    #+#             */
/*   Updated: 2022/06/11 18:23:14 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_list(t_list	*lst)
{
	if (!lst)
    {
		printf("Empty List\n");
        return ;
    }
	while (lst)
	{
		printf("List:%s\n", (char *)(lst->content));
		lst = lst->next;
	}
}
