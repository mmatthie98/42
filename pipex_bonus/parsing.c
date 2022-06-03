/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:11:24 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/03 15:33:51by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	init_data(t_data	*data)
{
	data->i = 0;
	data->j = 0;
	data->indicate = 0;
	data->lentab = ft_strlentab(data->arg);
}

int		check_file(char	*str, t_data	*data)
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
			perror("error");
			return(0);
		}
	}
	return(data->file1);
}

int		check_file2(char	*str, t_data	*data)
{
	int	i;

	i = 0;
	if (str && str[i])
	{
		data->file2 = open(str, O_RDWR | O_CREAT | O_NOCTTY | \
		O_TRUNC, 0677);
		if (data->file2 < 0)
		{
			perror("error");
			return(0);
		}
	}
	return (data->file2);
}

char	**get_cmd_split(char	*str, int c, int i,t_data *data)
{
	char	**cmd_split;

	(void) data;
	cmd_split = NULL;
	if (str && str[i])
		cmd_split = ft_split(str, c);
	if (!cmd_split)
	{
		printf("cmd_split error.\n");
		return (NULL);
	}
	return (cmd_split);
}

int	main(int ac, char	**av, char	**envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac > 4)
	{
		data->arg = &av[2];
		{
			if (check_file(av[1], data))
			{
				init_data(data);
				if (check_file2(av[data->lentab + 1], data))
				{
					if (check_envp(envp, data) == 0)
						ft_pipex(data, data->file1, data->arg, envp);
				}
			}
		}
	}
	else
		printf("use 4 parameter pls\n");
	//system("lsof -c pipex");
	return (0);
}

void	last_cmd_child(t_data	*data, char	*path_cmd, int in,char	**cmd,char	**envp)
{
	dup2(in, 0);
	dup2(data->file2, 1);
	close(data->file2);
	close(in);
	execve(path_cmd, cmd, envp);
}
