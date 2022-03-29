#include "c12.h"

static	void	ft_clear(void	*data)
{
	free (data);
	//data = '\0';
}

void	ft_lst_clear(t_list	*lst, void (*f)(void*))
{
	t_list	*li;

	while (lst)
	{
		f(lst->content);
		li = lst;
		lst = lst->next;
		free (li);
	}
	//lst->content = NULL;
}

int main()
{
	char	**tab;
	char	*str;
	t_list	*lst;
	int	i;

	str = "aloura ça se passe comment les listes mon khey ?! bon courage ! ça finira par payer!.\n";
	printf("nombre d'espace : %s.\n", str);
	tab = ft_split(str, ' ');
	i = ft_strlentab(tab);
	printf("voici le tableau \n___\n");
	ft_print_split(tab);
	printf("fin du tableau.\n");
	lst = ft_list_push_strs(i, tab);
	printf("%d\n", i);
	ft_print_list(lst);
	printf("on va clean la liste :\n");
	ft_lst_clear(lst, ft_clear);
	ft_print_list(lst);
	return (0);
}	