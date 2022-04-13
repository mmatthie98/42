#include "../include/push_swap.h"

void	init_struct_3(t_list	**a, t_data	*data)
{
	data->third = ft_atoi((*a)->next->next->content);
}

void	init_struct_2(t_list	**a, t_data *data)
{
	data->first = ft_atoi((*a)->content);
	data->second = ft_atoi((*a)->next->content);
}
void	init_struct_4(t_list	**a, t_data	*data)
{
	data->fourth = ft_atoi((*a)->next->next->next->content);
}

void	init_struct_5(t_list	**a, t_data	*data)
{
	data->five = ft_atoi((*a)->next->next->next->next->content);
}

void	init_data(t_data	*data)
{
	data->i = 0;
	data->j = 0;
	data->maplen = ft_strlentab(data->map);
}
