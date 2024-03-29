# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cocobongo <cocobongo@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 14:04:53 by tbrandt           #+#    #+#              #
#    Updated: 2023/10/06 14:36:59 by cocobongo        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g #fsanitize=address
NAME	=	minishell

SRC		=	main.c						\
			lexer/add_space.c			\
			lexer/add_space2.c			\
			lexer/expend.c				\
			lexer/expend2.c				\
			lexer/ft_exit.c				\
			lexer/get_word.c			\
			lexer/word_in_list.c		\
			lexer/join_and_free.c		\
			lexer/parsing2.c			\
			lexer/parsing.c				\
			lexer/utils.c				\
			lexer/utils2.c				\
			lexer/utils3.c				\
			lexer/utils4.c				\
			parser/tokenize.c			\
			parser/redirection_out.c	\
			parser/heredoc.c			\
			parser/pipe_and_fork.c		\
			executor/exec.c				\
			executor/get_path.c			\
			executor/get_command.c		\
			executor/utils2.c			\
			executor/utils3.c			\
			built_in/export.c			\
			built_in/echo.c				\
			built_in/pwd.c				\
			built_in/pwd_utils.c		\
			built_in/utils.c			\
			built_in/utils2.c			\
			built_in/utils3.c			\
			built_in/utils4.c			\
			built_in/utils5.c			\
			built_in/utils6.c			\
			built_in/utils7.c			\
			built_in/utils8.c			\
			built_in/utils9.c			\
			built_in/utils10.c			\
			signal/echoctl.c			\
			signal/signal.c				\
			signal/exit_code.c			\

OBJ		=	$(SRC:%.c=%.o)

LIBS    =   -L/usr/local/opt/readline/lib -lreadline
HEADERS =   -I/usr/local/opt/readline/include

all: $(NAME)

$(NAME): libft/libft.a libreadline $(OBJ)
	$(CC) ${CFLAGS} -o $(NAME) $(OBJ) ${LIBS} -I include -L libft -lft

libft/libft.a:
	make -j -C libft

%.o: %.c
	$(CC) ${CFLAGS} -o $@ -c $< ${HEADERS}

libreadline:
	@echo "Vérification de l'installation de Readline..."
	@if ! brew list readline &>/dev/null; then \
	    echo "Readline n'est pas installé. Installation en cours..."; \
	    brew install readline; \
	    echo "Readline a été installé avec succès."; \
	fi


clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re make_libft
