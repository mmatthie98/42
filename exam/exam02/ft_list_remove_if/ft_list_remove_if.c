#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

void	putlst(t_list	*lst, char *msg)
{
	printf("IN PUTLST\n\n");
	while(lst)
	{
		printf("%s :%d\n", msg, *(int *)(lst->content));
		lst = lst->next;
	}
}
void	ft_list_remove_if(t_list	**begin_list, void	*data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*before;

	current = *begin_list;
	before = current;
	while (current)
	{
		if (cmp(current->content, data_ref) == 0)
		{
			free(current->content);
			free (current);
			before->next = before->next->next;
		}
		before = current;
		current = current->next;
	}

}

// void	ft_list_remove_if(t_list	**begin_list, void	*data_ref, int (*cmp)())
// {
// 	t_list	*current;
// 	t_list	*queue;
// 	t_list	*before;

// 	current = *begin_list;
// 	while (current)
// 	{
// 		if (cmp(current->content, data_ref) == 0)
// 		{
// 			before = current;
// 			queue = current->next;
// 			current->next = queue;
// 			free(before->content);
// 			free (before);
// 		}
// 		else
// 			current = current->next;
// 	}
// 	putlst(*begin_list, "curent");
// }

t_list	*lstnew(int x)
{
	t_list	*new;
	int *y;

	new = malloc(sizeof(t_list) * 1);
	y = malloc(4);
	*y = x;
	new->content = y;
	new->next = NULL;
	return (new);
}

int	cmp(int *a, int *b)
{
	if (*a == *b)
		return (0);
	else
		return(1);
}

int main(void)
{
	t_list 	*begin;
	t_list	*el;
	int		data;

	begin = lstnew(5);
	data = 69;

	el = lstnew(6);
	begin->next = el;
	el = lstnew(69);
	begin->next->next = el;
	ft_list_remove_if(&begin, &data, &cmp);
	putlst(begin, "msg");
	return (0);
}
