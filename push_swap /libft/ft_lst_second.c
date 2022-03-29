#include	"../include/libft.h"

t_list	*ft_lst_second(t_list	**a)
{
	t_list	*tmp;

	tmp = *a;
	if ((*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = NULL;
		*a = tmp;
	}
	return (tmp);
}
