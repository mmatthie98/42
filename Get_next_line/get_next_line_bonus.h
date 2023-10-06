/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocobongo <cocobongo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:11:15 by mmatthie          #+#    #+#             */
/*   Updated: 2023/10/06 10:16:07 by cocobongo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define FD_MAX 257
# define BUFFER_SIZE 42

# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(char	*str);
char	*ft_isn(char	*str, int c);
char	*ft_strjoin(char	*src, char	*dest);
char	*ft_makeline(char	*save);
char	*ft_restline(char	*save);
char	*get_next_line(int fd);

#endif
