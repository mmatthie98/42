/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:54:28 by tbrandt           #+#    #+#             */
/*   Updated: 2022/06/12 17:21:40 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *create_list(char **buffer_splited)
{
	t_list	*lst;
	int		i;

	i = 1;
	lst = ft_lstnew(buffer_splited[0]);
	while (buffer_splited[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(buffer_splited[i]));
		i++;
	}
	return (lst);
}
