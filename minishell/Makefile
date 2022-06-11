# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 14:04:53 by tbrandt           #+#    #+#              #
#    Updated: 2022/06/11 18:23:07 by mmatthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g #-fsanitize=address
NAME	=	minishell

SRC		=	main.c			\
			create_list.c	\
			utils.c			\

OBJ		=	$(SRC:%.c=%.o)

LIBS    =   -L/Users/mmatthie/.brew/opt/readline/lib -lreadline
HEADERS =   -I$(HEADER) -I/Users/mmatthie/.brew/opt/readline/include

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	$(CC) ${CFLAGS} -o $(NAME) $(OBJ) ${LIBS} -I include -L libft -lft

libft/libft.a:
	make -j -C libft

%.o: %.c
	$(CC) ${CFLAGS} -o $@ -c $< ${HEADERS}

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re make_libft
