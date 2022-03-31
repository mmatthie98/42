/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:53:47 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/31 20:25:13 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	cnt_wd(const char	*str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			if (str[i] == c)
				ft_quit_with_msg("error.\nyou have empty line.\n");
		}
		else
		{
			j++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (j);
}

static char	*ft_word(const char *str, char c, t_data	*data)
{
	int		i;
	char	*wd;

	i = 0;
	while (*str && *str == c)
	{
		data->count_n++;
		str++;
	}
	while (str[i] && str[i] != c)
		i++;
	wd = malloc(sizeof(char) * (i + 1));
	if (!wd)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		wd[i] = str[i];
		i++;
	}
	wd[i] = '\0';
	return (wd);
}

void	free_wd(int i, char	**ptr)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free (ptr);
}

char	**ft_split(char const	*s, char c, t_data	*data)
{
	char	**ptr;
	int		w;
	int		i;

	if (!s)
		return (NULL);
	w = cnt_wd(s, c);
	ptr = malloc(sizeof(char *) * (w + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < w)
	{
		while (*s && *s == c)
			s++;
		ptr[i] = ft_word(s, c, data);
		if (ptr == NULL)
			free_wd(i, ptr);
		while (*s && *s != c)
			s++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

void	ft_free_map(char	**map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	map = NULL;
}
