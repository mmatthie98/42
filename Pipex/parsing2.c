/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocobongo <cocobongo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:15:01 by mmatthie          #+#    #+#             */
/*   Updated: 2023/10/06 11:47:21 by cocobongo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	get_empty_env(t_data	*data)
{
	data->envp = calloc(1, 1);
	data->envp[0] = " ";
	data->env = calloc(1, 1);
	data->env[0] = " ";
}

int	check_envp(char	**envp, t_data	*data)
{
	int	i;

	i = 0;
	if (!envp)
		get_empty_env(data);
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
	make_path(data, envp);
	return (0);
}

int	exec_last_cmd(char *last_cmd, int in, t_data	*data)
{
	char	**cmd;
	int		pid;
	char	*path_cmd;

	path_cmd = NULL;
	cmd = make_last_cmd(last_cmd);
	if (cmd && cmd[0])
		path_cmd = make_cmd_path(cmd[0], data);
	else
	{
		path_cmd = ft_strdup(" /");
		cmd = ft_split(data->cmd_path, ' ');
	}
	pid = fork();
	if (pid == 0)
		last_cmd_child(data, path_cmd, in, cmd);
	close(in);
	close(data->file2);
	waitpid(-1, NULL, 0);
	free(path_cmd);
	ft_free_split(cmd);
	return (0);
}

void	child_process(t_data	*data, int in, int	*fd, char	**cmd)
{
	dup2(in, 0);
	dup2(fd[1], 1);
	close(in);
	close(fd[1]);
	close(fd[0]);
	if (execve(data->cmd_path, cmd, data->envp) == -1)
		ft_putstr_fd("zsh : command not found\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_pipex(t_data	*data, int in, char **cmd, char	**envp)
{
	int		fd[2];
	int		pid;

	if (cmd[2])
		make_cmd(cmd, data);
	else
		return (exec_last_cmd(cmd[0], in, data));
	if (pipe(fd) == -1)
	{
		perror("zsh");
		return (2);
	}
	pid = fork();
	if (pid == 0)
		child_process(data, in, fd, data->cmd_splited);
	close(fd[1]);
	close(in);
	free(data->cmd_path);
	ft_free_split(data->cmd_splited);
	//system("leaks pipex");
	return (ft_pipex(data, fd[0], &cmd[1], envp));
}
