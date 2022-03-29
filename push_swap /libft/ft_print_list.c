#include "../include/libft.h"

/*static void    ft_print_content(void  *content)
{
    printf("%s", content);
}*/

void	ft_print_list(t_list	*lst)
{
    while (lst)
    {
	    printf("%s\n", (lst->content));
	    lst = lst->next;
    }
    if (!lst)
        printf("NULL\n");
}