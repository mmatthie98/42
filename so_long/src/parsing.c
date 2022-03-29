/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:20:52 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/29 21:28:40 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		if (!ft_check_nl(buf))
		{
			buf[byte_read] = '\0';
			str = ft_strjoin(str, buf);
			if (!str)
				return (NULL);
		}
		else
			ft_quit_with_msg("Error\nonly use allowed character.\n");
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

char	**parse(char *filename)
{
	int		fd;
	char	*str;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("error in fd.\n");
		exit (2);
	}
	str = ft_read_file(fd);
	close(fd);
	if (!str)
		return (NULL);
	map = ft_split(str, '\n');
	if (!map)
		return (NULL);
	free (str);
	return (map);
}

void	ft_quit_with_msg(char *str)
{
	printf("%s", str);
	exit(EXIT_FAILURE);
}
