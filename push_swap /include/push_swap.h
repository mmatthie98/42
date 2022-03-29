/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:09:15 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/28 12:29:49 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "../include/libft.h"

int     parse(char    **map);
size_t  ft_strlentab(char   **map);
char    **split_multiple_param(char  **tab);
int     ft_puti(int nb);
void    ft_putc(char c);
int is_max_or_min(char  **map);
void	ft_PA(t_list	**a, t_list	**b);
void	ft_reverse_rotate(t_list	**a);
void	ft_rotate(t_list	**a);
void	ft_PB(t_list	**a, t_list	**b);
void	SA(t_list	**a);
void	SS(t_list	**a, t_list	**b);
int		ft_is_sort(t_list	**a);
int		check(char	**map);
void	small_sort(t_list	**a, t_data	*data);
void	ft_sort_4(t_list	**a, t_list	**b, t_data	*data);
void	init_struct_3(t_list	**a, t_data	*data);
void	init_struct_4(t_list	**a, t_data	*data);
void	init_struct_5(t_list	**a, t_data	*data);
void	ft_get_high(t_list	**a, t_data	*data);
void	ft_low_sort(t_list	**a,t_list	**b, t_data	*data);
void	ft_sort_5(t_list	**a, t_list	**b, t_data	*data);
void	init_struct_2(t_list	**a, t_data	*data);
void	ft_sort_it(t_list	**a);
#endif
