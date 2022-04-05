#include "../include/push_swap.h"

void	ft_sort_2(t_list	**a, t_data	*data)
{
	init_struct_2(a, data);
	SA(a);
}

void	ft_sort_3(t_list	**a,t_data	*data)
{
	init_struct_2(a, data);
	init_struct_3(a, data);
	small_sort(a, data);
}

void	ft_sort_for_4(t_list	**a, t_list	**b, t_data	*data)
{
	init_struct_2(a, data);
	init_struct_3(a, data);
	init_struct_4(a, data);
	ft_get_low(a, data);
	ft_sort_4(a, b, data);
}

void	sort_for_5(t_list	**a, t_list	**b, t_data	*data)
{
	init_struct_2(a, data);
	init_struct_3(a, data);
	init_struct_4(a, data);
	init_struct_5(a, data);
	ft_print_list(*a);
	ft_get_low_5(a, data);
	printf("value of content %d\n", data->max_value);
	ft_print_list(*a);
	b = NULL;
	//ft_sort_5(a, b, data);
}
