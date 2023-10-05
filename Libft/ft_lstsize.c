

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*t;
	int		len;

	if (!lst)
		return (0);
	len = 1;
	t = lst->next;
	while (t != NULL)
	{
		t = t->next;
		len++;
	}
	return (len);
}
