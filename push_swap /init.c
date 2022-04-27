#include "../include/push_swap.h"

void	init_struct(t_data	*data,t_list	**a)
{
	if (data->size > 1)
	{
		data->first = (*(*a)->content);
		data->second = (*(*a)->next->content);
	}
	if (data->size > 2)
		data->third = (*(*a)->next->next->content);
	if (data->size > 3)
		data->fourth = (*(*a)->next->next->next->content);
	if (data->size > 4)
		data->five = (*(*a)->next->next->next->next->content);

}

void	init_data(t_data	*data)
{
	data->i = 0;
	data->j = 0;
	data->maplen = ft_strlentab(data->map);
	data->binary_size = ft_get_binary_size(data->max_value);
}
