/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:20:52 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/06 13:26:50 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_file(int fd)
{
	int		byte_read;
	char	buf[100];
	char	*str;

	str = NULL;
	byte_read = 1;
	while (byte_read)
	{
		byte_read = read(fd, buf, 100);
		if (byte_read == -1)
			ft_quit_with_msg("Error\nRead error.\n");
		buf[byte_read] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (NULL);
	}
	return (str);
}

size_t	ft_strlen_tab(char	**map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**parse(char *filename, t_data	*data)
{
	int		fd;
	char	*str;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_quit_with_msg("error in fd.\n");
	str = ft_read_file(fd);
	close(fd);
	if (!str)
		return (NULL);
	map = ft_split(str, '\n', data);
	if (!map)
		return (NULL);
	free (str);
	return (map);
}

void	ft_quit_with_msg(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}
