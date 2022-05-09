#include "pipex.h"

void	init_data(t_data	*data)
{
	data->i = 0;
	data->j = 0;
}

char	**ft_parse_arg(char	**tab, t_data	*data)
{
	init_data(data);
	while (tab[data->i])
	{
		while(tab[data->i][data->j])
			ft_split(tab[data->i][data->j], ' ');
		data->j++;
		data->i++;
	}
}

int	main(int	ac, char	**av, char const	*env)
{
	t_data	*data;
	int	i;

	i = 0;
	data = malloc(sizeof(t_data));
	if (ac > 1)
	{
		data->arg = ft_parse_arg(&av, data);
		ft_print_split(data->arg);
	}
	return (0);

}
