#include "include/push_swap.h"

int main ()
{
	void	*content;
	void	*content1;
	void	*content2;
	t_list	*lst;
	t_list	*lst1;
	t_list	*lst2;
	t_list	*b;

	b = NULL;
	content = "2";
	content1 = "4";
	content2 = "3";
	lst = ft_lstnew(content);
	lst1 = ft_lstnew(content1);
	lst2 = ft_lstnew(content2);
	ft_lstadd_back(&lst, lst1);
	ft_lstadd_back(&lst, lst2);
	printf("1 : lst avant pb :\n");
	ft_print_list(lst);
	ft_PB(&lst, &b);
	ft_print_list(lst);
	printf("stack b :\n");
	ft_print_list(b);
	printf("2 : lst avant 2eme pb :\n");
	ft_print_list(lst);
	ft_PB(&lst, &b);
	printf("lst\n");
	ft_print_list(lst);
	printf("stack b :\n");
	ft_print_list(b);
	printf("3 : lst avant pb :\n");
	ft_print_list(lst);
	ft_PB(&lst, &b);
	ft_print_list(lst);
	printf("stack b :\n");
	ft_print_list(b);
	printf("1 : lst avant pa :\n");
	ft_print_list(lst);
	ft_PA(&lst, &b);
	ft_print_list(lst);
	printf("stack b :\n");
	ft_print_list(b);
	printf("2 : lst avant pa :\n");
	ft_print_list(lst);
	ft_PA(&lst, &b);
	ft_print_list(lst);
	printf("stack b :\n");
	ft_print_list(b);
	printf("3 : lst avant pa :\n");
	ft_print_list(lst);
	ft_PA(&lst, &b);
	ft_print_list(lst);
	printf("stack b :\n");
	ft_print_list(b);
	return (0);
}
