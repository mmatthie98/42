#include "pipex.h"

void	init_data(t_data	*data)
{
	data->i = 0;
	data->j = 0;
}

int	main(int	ac, char	**av, char const	*env)
{
	t_data	*data;
	int	i;

	i = 0;
	data = malloc(sizeof(t_data));
	if (ac > 1)
	{
		//data->arg = ft_parse_arg(&av, data);
		



}