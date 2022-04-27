#include "../include/push_swap.h"

void	ft_sort_2(t_list	**a, t_data	*data)
{
	init_struct(data, a);
	SA(a);
}

void	ft_sort_3(t_list	**a, t_data	*data)
{
	data->size = ft_lstsize(*a);
	init_struct(data, a);
	small_sort(a, data);
}

void	ft_sort_for_4(t_list	**a, t_list	**b, t_data	*data)
{
	init_struct(data, a);
	ft_get_low(data);
	ft_sort_4(a, b, data);
}

void	sort_for_5(t_list	**a, t_list	**b, t_data	*data)
{
	init_struct(data, a);
	ft_get_low_5(data);
	ft_sort_5(a, b, data);
}
