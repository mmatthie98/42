/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:07:48 by tbrandt           #+#    #+#             */
/*   Updated: 2022/06/17 16:31:42 by mmatthie         ###   ########.fr       */
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

int	get_quotes(char	*str, t_data *data, int count)
{
	int	i;
	int	j;

	i = 0;
	j = count;
	data->token = str[count];
	count++;
	while (str[++j] != data->token && str[j] != '\0')
		i++;
	data->first = ft_calloc(1, i);
	data->first = ft_strncpy(data->first, &str[count], i);
	j += 1;
	if (str[j] != ' ' && str[j] != '\0')
		j = pre_join(str, data, j);
	count = j;
	return (count);
}

t_list	*get_word_in_list(char	*buffer, t_data	*data)
{
	t_list	*lst;
	int	i;

	i = -1;
	data->count = 0;
	lst = NULL;
	data->indicate = 0;
	while (data->count < (int)ft_strlen(buffer))
	{
		while (ft_isspace(buffer[data->count]))
			data->count++;
		if (buffer[data->count] != '"' && buffer[data->count] != '\'' && buffer[data->count] != '\0')
		{
			data->count = get_word(buffer, data, data->count);
			lst = ft_list(lst, data->first);
		}
		/*if (ft_strcmp(data->first, "export"))
			lst = get_export_list()*/
		else if (buffer[data->count] == '"' || buffer[data->count] == '\'')
		{
			data->count = get_quotes(buffer, data, data->count);
			lst = ft_list(lst, data->first);
		}
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
		add_history(buffer);\
	}
	free(buffer);
	return (0);
}
