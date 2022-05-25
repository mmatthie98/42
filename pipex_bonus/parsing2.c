#include "include/pipex_bonus.h"

int	check_envp(char	**envp, t_data	*data)
{
	init_data(data);
	if (!envp)
		perror("error");
	while (envp[data->i] && !ft_strncmp(envp[data->i], "PATH", 4))
		data->i++;
	data->env = ft_split(envp[data->i], ':');
	if (!data->env)
		perror("error");
	ft_print_split(data->env);
	return (0);
}