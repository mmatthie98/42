/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:15:01 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/01 16:22:31 by mmatthie         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if ((ft_strncmp(envp[i], "PATH", 4) != 0))
			i++;
		else
		{
			data->env = ft_split(envp[i] + 5, ':');
			i++;
		}
	}
	if (!data->env)
	{
		printf("stop trying bullshit test bro!\n");
		data->env = calloc(1, 1);
		data->env[0] = "\0";
	}
	make_path(data);
	return (0);
}

int	exec_last_cmd(char *last_cmd, char **envp, int in, t_data	*data)
{
	char	**cmd;
	int		pid;
	char	*path_cmd;

	cmd = ft_split(last_cmd, ' ');
	path_cmd = make_cmd_path(cmd[0], data);
	pid = fork();
	if (pid == 0)
		last_cmd_child(data, path_cmd, in, cmd, envp);
	waitpid(-1 , NULL, 0);
	close(in);
	close(data->file2);
	free(path_cmd);
	ft_free_split(cmd);
	return (0);
}

void	child_process(t_data	*data, int in, int	*fd, char	**cmd, char	**envp)
{
	dup2(in, 0);
	dup2(fd[1], 1);
	close(in);
	close(fd[1]);
	close(fd[0]);
	execve(data->cmd_path, cmd, envp);
}

int	ft_pipex(t_data	*data, int	in, char **cmd, char	**envp)
{
	int		fd[2];
	int		pid;

	if (cmd[2])
	{
		data->cmd_splited =	ft_split(cmd[0], ' ');
		data->cmd_path = make_cmd_path(data->cmd_splited[0], data);
	}
	else
		return (exec_last_cmd(cmd[0], envp, in, data));
	if (pipe(fd) == -1)
	{
		perror("error : ");
		return (2);
	}
	pid = fork();
	if (pid == 0)
		child_process(data , in, fd, data->cmd_splited, envp);
	close(fd[1]);
	close(in);
	waitpid(-1, NULL, 0);
	free(data->cmd_path);
	ft_free_split(data->cmd_splited);
	return(ft_pipex(data, fd[0], &cmd[1], envp));
}
