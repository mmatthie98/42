#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_strlen(char	*str)
{
	int i = 0;

	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_strdup(char	*str)
{
	char	*newline;
	int len = ft_strlen(str);

	newline = malloc(sizeof(char) * len + 1);
	if (!newline)
		return (NULL);
	newline[len] = '\0';
	len = 0;
	while (str[len])
	{
		newline[len] = str[len];
		len++;
	}
	return (newline);
}

char	**get_cmd(char	**av)
{
	int i = 0;
	char	**cmd;

	while (av[i] && strcmp(";", av[i]) && strcmp("|", av[i]))
		i++;
	if (!i)
		return (NULL);
	cmd = malloc(sizeof(char *) * i + 1);
	cmd[i] = NULL;
	while (--i >= 0)
		cmd[i] = ft_strdup(av[i]);
	return (cmd);
}

void full_free(char	**cmd)
{
	int i = 0;

	while (cmd && cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free (cmd);
}

void	cd(char	**av)
{
	int i = 0;

	while (av[i])
		i++;
	if (i != 2)
		write(2, "error bad nb of args", 20);
	else
	{
		if (chdir(av[1]) == -1)
		{
			write(2, "error in open ", 14);
			write(2, av[1], ft_strlen(av[1]));
		}
	}
}

void	exec_cmd(char	**av, char	**env)
{
	int pid;

	if (!strcmp("cd", av[1]))
	{
		cd(av);
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		write(2, "error\n", 6);
		exit(-1);
	}
	if (!pid)
	{
		if (execve(av[0], av, env) == -1)
		{
			write(2, "error\n", 6);
			write(2, av[0], ft_strlen(av[0]));
			write(2, "\n", 1);
			exit (-1);
		}
	}
	else
		waitpid(pid, NULL, 0);
}

int end_pipe(char	**cmd, char	**env, int in)
{
	int pid;

	pid = fork();
	if (pid == -1)
	{
		write(2 , "error\n", 6);
		exit(-1);
	}
	if (!pid)
	{
		dup2(in, 0);
		close(in);
		if (execve(cmd[0], cmd, env) == -1)
		{
			write(2, "error\n", 6);
			write(2, cmd[0], ft_strlen(cmd[0]));
			write(2, "\n", 1);
			close(1);
			close(0);
			exit (-1);
		}
	}
	return (1);
}

int pipex(char	**cmd, char	**av, char	**env, int in, int i)
{
	int pid;
	int fd[2];
	static int j = 0;

	if (pipe(fd) == -1)
	{
		write(2, "error\n",  6);
		exit(-1);
	}
	pid = fork();
	if (pid == -1)
	{
		write(2, "error\n",  6);
		exit(-1);	
	}
	if (!pid)
	{
		dup2(in, 0);
		dup2(fd[1], 1);
		close(in);
		close(fd[1]);
		if (execve(cmd[0], cmd, env) == -1)
		{
			write(2, "error\n", 6);
			write(2, cmd[0], ft_strlen(cmd[0]));
			write(2, "\n", 1);
			close(0);
			close(1);
			close(fd[0]);
			exit (-1);
		}
	}
	else
	{
		j++;
		close(fd[1]);
		if (in)
			close(in);
		full_free(cmd);
		cmd = get_cmd(&av[i]);
		while (av[i] && strcmp(";", av[i]) && strcmp("|", av[i]))
			i++;
		if (av[i] && !strcmp("|", av[i]) && av[i + 1])
			return(pipex(cmd, av, env, fd[0], ++i));
		else if (av[i] && !strcmp(";", av[i]) && av[i + 1])
			i++;
		else
			i = 0;
		j += end_pipe(cmd, env, fd[0]);
		close(fd[0]);
		while (j--)
			waitpid(-1, NULL, 0);
		full_free(cmd);
	}
	return (i);
}

int main(int ac, char	**av, char	**env)
{
	int i = 1;
	char	**cmd;

	while (ac > 1 && i)
	{
		cmd = get_cmd(&av[i]);
		if (!cmd && av[i + 1])
		{
			i++;
			continue;
		}
		else if (!cmd && !av[i + 1])
			break;
		while (av[i] && strcmp(";", av[i]) && strcmp("|", av[i]))
			i++;
		if (av[i] && !strcmp(";", av[i]) && av[i + 1])
		{
			exec_cmd(cmd, env);
			full_free(cmd);
			i++;
		}
		else if (av[i] && !strcmp("|", av[i]) && av[i + 1])
			i = pipex(cmd, av, env, 0, ++i);
		else
		{
			exec_cmd(cmd, env);
			full_free(cmd);
			break;
		}
	
	}
	return (0);
}