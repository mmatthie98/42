/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:15:01 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/25 18:55:47 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

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

void	ft_pipex(t_data	*data, char	**envp)
{
	int status1;
	int	status2;
	pid_t child1;
	pid_t child2;

	init_data(data);
	pipe(data->fd);
	if (pipe(data->fd) < 0)
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
		child2_prog(data, envp);
	if (child2 > 0)
	{
		status2 = waitpid(child2, NULL, 0);
		printf("wait for status2 %d\n", status2);
	}
	close(data->fd[0]);
	close(data->fd[1]);
	
}

void	child1_prog(t_data	*data, char	**envp)
{
	init_data(data);
	int	i;

	i = 0;
	dup2(data->file1, STDIN_FILENO);
	if (dup2 < 0)
		perror("dup2");
	dup2(data->fd[1], STDOUT_FILENO);
	if (dup2 < 0)
		perror("dup2");
	close(data->fd[0]);
	close(data->file1);
	while (data->env[++i])
	{
		data->cmd_to_rotate = ft_strjoin(data->env[i], data->cmd1);
		if (!data->cmd_to_rotate)
			perror("join");
		data->j = execve(data->cmd_to_rotate, data->split_arg1, envp);
		if (data->j == -1)
			perror("execve");
		free(data->cmd_to_rotate);
	}
}

void	child2_prog(t_data	*data, char	**envp)
{
	init_data(data);
	int	i;

	i = 0;
	dup2(data->fd[0], STDIN_FILENO);
	if (dup2 < 0)
		perror("dup2");
	dup2(data->fd[1], STDOUT_FILENO);
	if (dup2 < 0)
		perror("dup2");
	close(data->fd[1]);
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


