#include "c12.h"

void	ft_lst_push_back(t_list	**begin, void	*data)
{
	t_list	*lst;
	t_list	*li;

	li = *begin;
	lst = ft_create_element(data);
	while (li && li->next)
		lst = li->next;
	li->next = lst;
}
