# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 17:52:59 by mmatthie          #+#    #+#              #
#    Updated: 2022/02/25 13:24:24 by mmatthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g

NAME		=	libft.a

OBJ			=	${SRC:.c=.o}

I_DIR		=	.

SRC			=	ft_memset.c		\
				ft_lst_second.c	\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memmove.c 	\
				ft_memchr.c		\
				ft_strlen.c		\
				ft_isalpha.c 	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_strchr.c		\
				ft_strncmp.c	\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_strnstr.c	\
				ft_atoi.c		\
				ft_calloc.c		\
				ft_strdup.c		\
				ft_itoa.c		\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_striteri.c	\
				ft_substr.c		\
				ft_strrchr.c	\
				ft_strtrim.c	\
				ft_strmapi.c	\
				ft_strjoin.c	\
				ft_memcmp.c		\
				ft_split.c		\
				ft_atoll.c		\
				ft_isascii.c	\
				ft_print_split.c \
				ft_strlentab.c	\
				ft_isspace.c	\
				ft_strcmp.c		\
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_print_list.c		\

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
