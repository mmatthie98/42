/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:15:01 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/08 18:08:12 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	*ft_manag(void	*ptr)
{
	static t_list	*lst;

	ft_lstadd_back(&lst, ft_lstnew(ptr));
	return (ptr);
}

void	ft_free_split(char	**to_free)
{
	size_t	i;

	i = 0;
	if (!to_free)
		return ;
	while(to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

void	get_empty_env(t_data	*data)
{
	data->envp = calloc(1, 1);
	data->envp[0] = "\0";
	data->env = calloc(1, 1);
	data->env[0] = "\0";
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

	cmd = ft_split(last_cmd, ' ');
	path_cmd = make_cmd_path(cmd[0], data);
	if (access(path_cmd, X_OK | F_OK) == -1)
	{
		printf("path_cmd == -1");
		printf("zsh : command not found.\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		last_cmd_child(data, path_cmd, in, cmd);
	close(in);
	close(data->file2);
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
	{
		ft_putstr_fd("zsh : command not found\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	ft_pipex(t_data	*data, int	in, char **cmd, char	**envp)
{
	int		fd[2];
	int		pid;

	if (cmd[2])
	{
		data->cmd_splited =	ft_split(cmd[0], ' ');
		data->cmd_path = make_cmd_path(data->cmd_splited[0], data);
		if (access(data->cmd_path, X_OK | F_OK) == -1)
		{
			printf("path_cmd == -1\n");
			printf("zsh : command not found.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		return (exec_last_cmd(cmd[0], in, data));
	if (pipe(fd) == -1)
	{
		perror("error : ");
		return (2);
	}
	pid = fork();
	if (pid == 0)
		child_process(data , in, fd, data->cmd_splited);
	close(fd[1]);
	close(in);
	waitpid(-1, NULL, 0);
	free(data->cmd_path);
	ft_free_split(data->cmd_splited);
	return(ft_pipex(data, fd[0], &cmd[1], envp));
}

int	check_access(char	*path)
{
	return (access(path, F_OK | X_OK));
}
