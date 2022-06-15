/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:07:48 by tbrandt           #+#    #+#             */
/*   Updated: 2022/06/15 18:27:09 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_list(t_list	*lst, char	*str)
{
	t_list	*li;

	li = NULL;
	if (lst == NULL)
	{
		lst = ft_lstnew(str);
		return(lst);
	}
	else
	{
		li = ft_lstnew(str);
		ft_lstadd_back(&lst, li);
		return (lst);
	}
	return (lst);
}

t_list	*get_word_in_list(char	*buffer, t_data	*data)
{
	t_list	*lst;
	int	i;

	i = -1;
	data->count = 0;
	lst = NULL;
	//printf("data->count : %d\n", data->count);
	while (data->count < (int)ft_strlen(buffer))
	{
		while (ft_isspace(buffer[data->count]))
			data->count++;
		if (buffer[data->count] != '"' && buffer[data->count] != '\'' && buffer[data->count] != '\0' && buffer[data->count] != ' ')
		{
			data->count = get_word(buffer, data);
			lst = ft_list(lst, data->first);
		}
		/*else if (buffer[data->count] != '"' || buffer[data->count] != '\'')
		{

		}*/
	}
	return (lst);
}

int main()
{
	t_data	*data;
	t_list	*lst;
	char *buffer = NULL;

	data = malloc(sizeof(data));
	lst = NULL;
	while(1)
	{
		buffer = readline(">$ ");
		lst = get_word_in_list(buffer, data);
		ft_print_list(lst);
		add_history(buffer);
	}
	free(buffer);
	return (0);
}
