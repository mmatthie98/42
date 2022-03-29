#include "list.h"

t_list  *ft_newlist(void    *content)
{
    t_list  *lst;

    lst = malloc(sizeof(t_list));
    if (lst == NULL)
        return (NULL);
    lst->content = (int)content;
    lst->next = NULL;
    return (lst);
}

/***********************************************************************************************/

size_t  list_len(t_list *lst)
{
    size_t  i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

/***********************************************************************************************/

void    print_list(t_list *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        printf("%d\n", lst->content);
        lst = lst->next;
    }
}

/***********************************************************************************************/

void    ft_lst_add_front(t_list **lst, t_list  *new)
{
    if (*lst)
        new->next = *lst;
    *lst = new;
}

/***********************************************************************************************/

void    ft_lst_add_back(t_list  **lst, t_list   *new)
{
    t_list  *tmp;

    tmp = *lst;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
    if (!new)
        return ;
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}
/***********************************************************************************************/
/*                                  1, 2, 3 
                                    tmp = *lst = 1, 2, 3
                                    *lst = (*lst)->next; // ratacher au maillon suivant
                                    free(tmp);
                                    *lst = NULL
                                                                                                      */

void    lst_clear(t_list    **lst)
{
    t_list  *tmp;

    while (*lst)
    {
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp);
    }
    *lst = NULL;
}

/***********************************************************************************************/

void    ft_del(void *content)
{
    free(content);
    return ;
}

/***********************************************************************************************/
int main ()
{
    void    *content;
    void    *content2;
    void    *content3;

    content3 = (void*)2;
    content2 = (void*)0;
    content = (void*)-111-+12;
    t_list  *mynewlst = ft_newlist(content3);
    t_list *newlst = ft_newlist(content2);
    t_list *mylist = ft_newlist(content);
    printf("____1ere liste____\n");
    printf("____\n");
    print_list(mylist);
    printf("____\n");
    printf("mon premier maillon est initialisé a 1.\n");
    printf("je lui ajoute %d devant.\n", (int)content2);
    ft_lst_add_front(&mylist, newlst);
    printf("————\n");
    print_list(mylist);
    printf("____\n");
    printf("maintenant je vais ajouter %d derrière.\n", (int)content3);
    ft_lst_add_back(&mylist, mynewlst);
    printf("____3eme liste____\n");
    printf("____\n");
    print_list(mylist);
    printf("____\n");
    printf("puis je clean ma liste.\n");
    lst_clear(&mylist);
    printf("____liste vide____\n");
    print_list(mylist);
    printf("\n");
    return (0);
}