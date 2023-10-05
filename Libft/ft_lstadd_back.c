
#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*p;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	p = ft_lstlast(*alst);
	p->next = new;
}
