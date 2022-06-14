/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:07:48 by tbrandt           #+#    #+#             */
/*   Updated: 2022/06/14 11:22:11 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_get_all_args(char	*buffer, t_data	*data)
{
	t_list	*lst;
	t_list	*new_arg;
	int		len;

	len = ft_strlen(buffer);
	new_arg = NULL;
	lst = NULL;
	data->count = 0;
	while (data->count < len)
	{
		if (lst == NULL)
			lst = ft_get_first_args(buffer, data);
		else
		{
			new_arg = ft_get_first_args(buffer, data);
			ft_lstadd_back(&lst, new_arg);
		}
	}
	return(lst);
}

int main()
{
	t_data	*data;
	t_list	*lst;
	t_list	*new_arg;
	char *buffer = NULL;
	
	data = malloc(sizeof(data));
	lst = NULL;
	new_arg = NULL;
	while(1)
	{
		buffer = readline(">$ ");
		lst = ft_get_all_args(buffer, data);
		while (lst)
		{
			printf("lst->content : %s\n", lst->content);
			lst = lst->next;
		}
		exit(EXIT_SUCCESS);
		add_history(buffer);
	}
	free(buffer);
	return (0);
}
