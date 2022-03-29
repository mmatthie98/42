#ifndef LIST_H
#define LIST_H


typedef struct s_list
{
    int             content;
    struct s_list   *next;
}   t_list;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

t_list  newlist(t_list  *data);
#endif