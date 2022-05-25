#include "include/pipex_bonus.h"

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
				return(open(str, O_RDONLY));
		}
		if (n == 0)
		{
			data->j = open(str, O_RDWR);
			if (data->j < 0)
				return (open(str, O_CLOEXEC, O_CREAT, O_DIRECTORY,\
				O_EXCL, O_NOCTTY, O_NOFOLLOW, O_TRUNC));
			else
				return (open(str, O_RDWR));
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
		if (check_envp(envp, data) == 0)
		{
			/*if (check_heredoc(av, data)) // try to found if here_doc is present if yes then the algo will do the bonuses
				here_algo(av, data);*/
			if (check_file(av[1], data, 1) == 0) // check if file is a file
			{
				if (check_file(av[data->lentab - 1], data, 0) > 0) // check if the last file exist, in other way, open will created it
				{
					data->i += 2;
					while (data->i < data->lentab - 1)
					{	
						if (check_cmd(av[data->i], data) == 0)
						{
							printf("it's ok\n"); //pipe_it(data);
							data->i++;
						}
					}
				}
			}
		}
	}
	else
		printf("use 4 parameter pls\n");
	return (0);
}
