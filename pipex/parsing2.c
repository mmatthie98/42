/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:15:01 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/30 16:43:15 by mmatthie         ###   ########.fr       */
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
	char 	*str;
	init_data(data);
	if (!envp)
		perror("error");
	while (envp[data->i] && ft_strncmp(envp[data->i], "PATH", 4) != 0)
		data->i++;
	data->env = ft_split(envp[data->i], ':');
	if (!data->env)
		perror("error");
	str = make_cmd(data);
	free (data->env[0]);
	data->env[0] = str;
	make_path(data);
	return (0);
}

char	*make_cmd(t_data	*data)
{
	init_data(data);
	char	*str;
	int		i;
	int		j;
	int 	len;

	len = ft_strlen(data->env[0]);
	i = 0;
	while (data->env[0][i] != '=')
		i++;
	str = malloc(sizeof(char) * len - i + 1);
	j = 0;
	i += 1;
	while(data->env[0][i])
	{
		str[j] = data->env[0][i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

int	ft_pipex(t_data	*data, int	in, char **cmd, char	**envp)
{
	int		fd[2];
	int		pid;
	char	**cmd_splited;

	cmd_splited = ft_split(cmd[0], ' ');
	if (!cmd)
		return (0);
	data->cmd_path = make_cmd_path(data);
	if (pipe(fd) == -1)
	{
		perror("error : ");
		return (1);
	}
	pid = fork();
	if (!pid)
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
	return (ft_pipex(data, fd[0], &cmd[1], envp));
}
/*
void	ft_pipex(t_data	*data, char	**envp)
{
	int status1;
	int	status2;
	pid_t child1;
	pid_t child2;

	init_data(data);
	pipe(data->pipe_fd);
	if (pipe(data->pipe_fd) < 0)
		perror("pipe");
	child1 = fork();
	if (child1 < 0)
		return (perror("error"));
	if (child1 == 0)
		child1_prog(data, envp); // execute first cmd
	if (child1 > 0)
	{
		status1 = waitpid(child1, NULL, 0);
		printf("wait for status1 %d\n", child1);
	}
	child2 = fork();
	if (child2 < 0)
		return (perror("error"));
	if (child2 == 0)
		child2_prog(data, envp); //execute second cmd
	if (child2 > 0)
	{
		status2 = waitpid(child2, NULL, 0);
		printf("wait for status2 %d\n", status2);
	}
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
}*/

void	child1_prog(t_data	*data, char	**envp)
{
	init_data(data);
	int	i;

	i = 0;
	dup2(data->file1, STDIN_FILENO);
	if (dup2 < 0)
		perror("dup2");
	dup2(data->pipe_fd[1], STDOUT_FILENO);
	if (dup2 < 0)
		perror("dup2");
	close(data->pipe_fd[0]);
	close(data->file1);
	while (data->env[++i])
	{
		data->cmd_to_rotate = ft_strjoin(data->env[i], data->cmd1);
		if (!data->cmd_to_rotate)
			perror("join");
		if (access(data->cmd_to_rotate, F_OK | X_OK) == 0)
			execve(data->cmd_to_rotate, data->split_arg1, envp);
		free(data->cmd_to_rotate);
	}
}

void	child2_prog(t_data	*data, char	**envp)
{
	init_data(data);
	int	i;

	i = 0;
	dup2(data->pipe_fd[0], STDIN_FILENO);
	if (dup2 < 0)
		perror("dup2");
	dup2(data->pipe_fd[1], STDOUT_FILENO);
	if (dup2 < 0)
		perror("dup2");
	close(data->pipe_fd[1]);
	close(data->file2);
	while (data->env[++i])
	{
		data->cmd_to_rotate = ft_strjoin(data->env[i], data->cmd2);
		if (!data->cmd_to_rotate)
			perror("join");
		data->j = execve(data->cmd_to_rotate, data->split_arg2, envp);
		if (data->j == -1)
			perror("execve");
		free(data->cmd_to_rotate);
	}
}


