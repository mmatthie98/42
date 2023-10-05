/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:39:52 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/25 11:45:01 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	init_data(t_data	*data, char	**envp)
{
	if (envp)
		data->envp = envp;
	data->i = 0;
	data->j = 0;
	data->indicate = 0;
	data->lentab = ft_strlentab(data->arg);
}

int	check_file(char	*str, t_data	*data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str && str[i])
	{
		data->file1 = open(str, O_RDONLY);
		if (data->file1 < 0)
		{
			perror("zsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		data->file1 = open(str, O_RDONLY);
		if (data->file1 < 0)
		{
			perror("zsh");
			exit(EXIT_FAILURE);
		}
	}
	return (data->file1);
}

int	check_file2(char	*str, t_data	*data)
{
	int	i;

	i = 0;
	if (str && str[i])
	{
		data->file2 = open(str, O_RDWR | O_CREAT | O_NOCTTY | \
		O_TRUNC, 0677);
		if (data->file2 < 0)
			perror("zsh");
	}
	else
	{
		data->file2 = open(str, O_RDWR | O_CREAT | O_NOCTTY | \
		O_TRUNC, 0677);
		if (data->file2 < 0)
			perror("zsh");
	}
	return (data->file2);
}

int	main(int ac, char	**av, char	**envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac > 3)
	{
		data->arg = &av[2];
		init_data(data, envp);
		if (check_file2(av[data->lentab + 1], data))
			post_pipex(av, data);
	}
	else
		printf("use more than 4 parameter pls\n");
	return (0);
}
