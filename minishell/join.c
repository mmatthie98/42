/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:18:24 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/20 23:52:50 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	get_join(char	*str, int count, int j, t_data	*data)
{
	count = get_second_word(str, j, data);
	data->get_word = ft_calloc(1, ft_strlen(data->join) + 1);
	data->get_word = ft_strncpy \
	(data->get_word, data->join, ft_strlen(data->join));
	while (str[count] != ' ' && str[count])
	{
		count = get_second_word(str, count, data);
		data->get_word = ft_calloc(1, ft_strlen(data->join));
		data->get_word = ft_strncpy \
		(data->get_word, data->join, ft_strlen(data->join));
		data->first = ft_calloc(1, ft_strlen(data->join));
		data->first = ft_strncpy \
		(data->first, data->join, ft_strlen(data->join));
	}
	return (count);
}

char	*ft_join_free_ss(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1)
	{
		s1 = ft_calloc(1, 1);
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (NULL);
	join = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = 0;
	free(s1);
	free(s2);
	return (join);
}