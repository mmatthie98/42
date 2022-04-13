#include "c12.h"

void	ft_print_list(t_list	*lst)
{
	printf("list: \n");
	while (lst)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}
