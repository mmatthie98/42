/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:15:01 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/29 17:16:50 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	ft_free_split(char	**to_free)
{
	size_t	i;

	i = 0;
	while(to_free[i])
		free(to_free[i++]);
	free(to_free);
}

int	check_envp(char	**envp, t_data	*data)
{
	init_data(data);
	if (!envp)
		perror("error");
	while (envp[data->i] && ft_strncmp(envp[data->i], "PATH", 4) != 0)
		data->i++;
	data->env = ft_split(envp[data->i] + 5, ':');
	if (!data->env)
		perror("error");
	make_path(data);
	return (0);
}

int	ft_pipex(t_data	*data, int	in, char **cmd, char	**envp)
{
	int		fd[2];
	int		pid;
	char	**cmd_splited;

	data->i = 0;
	data->j = 0;
	cmd_splited = ft_split(cmd[0], ' ');
	if (!cmd)
		return (0);
	data->cmd_path = make_cmd_path(data->env[data->i], cmd_splited[0]);
	printf("data->cmd_path : %s\n", data->cmd_path);
	if (pipe(fd) == -1)
	{
		perror("error : ");
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(in, 0);
		dup2(fd[1], 1);
		close(in);
		close(fd[1]);
		if (!data->cmd_path)
		{
			ft_putstr_fd("command not found\n", 2);
			exit(1);
		}
		execve(data->cmd_path, cmd_splited, envp);
	}
	waitpid(-1, NULL, 0);
	free(data->cmd_path);
	ft_free_split(cmd_splited);
	data->i++;
	return (ft_pipex(data, fd[0], &cmd[1], envp));
}

char	*make_cmd_path(char	*str, char	*cmd)
{
	//need to join to cmd to path
	//need to check if join is ok and need to use env without infile and outfile.
	char	*s;

	s = NULL;
	if (*str && *cmd)
	{
		s = ft_strjoin(str, cmd);
		if (!s)
			return (NULL);
	}
	return (s);
}
