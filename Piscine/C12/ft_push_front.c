#include "c12.h"

void	ft_push_front(t_list	**begin, void	*content)
{
	t_list	*lst;

	lst = ft_create_element(content);
	if (!lst)
		return ;
	lst->content = content;
	lst->next = *begin;
	*begin = lst;
}