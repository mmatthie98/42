/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:11:24 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/25 12:24:44 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	init_data(t_data	*data)
{
	data->i = 0;
	data->j = 0;
	data->indicate = 0;
	data->lentab = ft_strlentab(data->arg);
	data->env = NULL;
	data->str = NULL;
}

int	check_cmd(char	*cmd, t_data	*data)
{
	int		fd;
	char	**tab;

	init_data(data);
	if (cmd && cmd[data->i])
	{
		tab = ft_split(cmd, ' ');
		if (!cmd)
			return (EXIT_FAILURE);
		fd = access(&cmd[data->i], X_OK );
		if (fd == -1)
			perror("error");
	}
	return (0);	
}

int		check_file(char	*str, t_data	*data, int n)
{
	init_data(data);
	if (str && str[data->i])
	{
		if (n > 0)
		{
			data->j = open(str, O_RDONLY);
			if (data->j < 0)
				perror("error");
			else
			{
				data->file1 = open(str, O_RDONLY);
				return(data->file1);
			}
		}
		if (n == 0)
		{
			data->j = open(str, O_WRONLY);
			if (data->j < 0)
			{
				data->file2 = open(str, O_CLOEXEC, O_CREAT, O_DIRECTORY,\
				O_EXCL, O_NOCTTY, O_NOFOLLOW, O_TRUNC);
				return (data->file2);
			}
			else
			{
				data->file2 = open(str, O_WRONLY);
				return (data->file2);
			}
		}
	}
	return (1);
}

int	main(int ac, char	**av, char	**envp)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	init_data(data);
	data->arg = av;
	if (ac > 3)
	{
		//ft_print_split(envp);
		if (check_envp(envp, data) == 0)
		{
			if (check_file(av[1], data, 1))
			{
				if (check_file(av[4], data, 0))
					//ft_pipex(data);
				{
					ft_print_split(data->arg);
					ft_print_split(data->env);
				}
			}
		}
	}
	else
		printf("use 4 parameter pls\n");
	return (0);
}