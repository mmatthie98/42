/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:15:01 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/08 20:11:14 by mmatthie         ###   ########.fr       */
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
	if (envp && envp[i])
	{
		while (envp[i] && ft_strncmp(envp[i], "PATH", 4) != 0)
			i++;
		data->env = ft_split(envp[i] + 5, ':');
		if (!data->env)
			data->env = NULL;
	}
	return (0);
}

void	dupnclose(int	*fd, int infile, t_data	*data)
{
	dup2(infile, 0);
	dup2(fd[1], 1);
	close (infile);
	close (fd[1]);
	close(fd[0]);
	close (data->file2);
}

void	dupnclose2(int *fd, t_data	*data)
{
	dup2(fd[0], 0);
	dup2(data->file2, 1);
	close (fd[0]);
	close (data->file2);
}

void	run2(t_data	*data, char	**envp)
{
	if (execve(data->cmd_path1, data->split_arg2, envp) == -1)
	{
		ft_putstr_fd("zsh : command not found\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	run(t_data	*data, char	**envp)
{
	if (execve(data->cmd_path2, data->split_arg1, envp) == -1)
	{
		ft_putstr_fd("zsh : command not found\n", 2);
		exit(EXIT_FAILURE);
	}
}

char	*make_cmd_path(char	*cmd, t_data	*data)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 1;
	s = NULL;
	if (cmd && cmd[0] == '/')
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		else
			return (NULL);
	}
	else if (data->env && data->env[i])
		s = get_good_path(cmd, data);
	return (s);
}

char	*get_good_path(char	*cmd, t_data	*data)
{
	char	*s;
	int		i;

	s = NULL;
	i = 0;
	while (data->env && data->env[i])
	{
		s = ft_strjoin_pipex(data->env[i], cmd);
		if (!s)
			return(NULL);
		if (access(s, X_OK | F_OK) == 0)
			return(s);
		free(s);
		i++;
	}
	return(s);
}

void	get_cmd_path(t_data	*data)
{
	if (!data->split_arg1)
		data->cmd_path1 = NULL;
	if (!data->split_arg2)
		data->cmd_path2 = NULL;
	else
	{
		data->cmd_path1 = make_cmd_path(data->split_arg1[0], data);
		data->cmd_path2 = make_cmd_path(data->split_arg2[0], data);
	}
}

int	ft_pipex(t_data	*data, int	in, char	**envp)
{
	int		fd[2];
	int		pid;
	int		pid1;

	get_cmd_path(data);
	if (pipe(fd) == -1)
	{
		perror("error : ");
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		dupnclose(fd, in, data);
		run(data, envp);
	}
	close(in);
	close(fd[1]);
	waitpid(-1, NULL, 0);
	pid1 = fork();
	if (pid1 == 0)
	{
		dupnclose2(fd, data);
		run2(data, envp);
	}
	waitpid(-1, NULL, 0);
	close(fd[0]);
	close(data->file2);
	return (0);
}

