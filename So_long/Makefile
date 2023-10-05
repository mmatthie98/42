CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

NAME = solong

I_DIR = include

L_DIR	= lib

SRC = 	src/so_long.c \
		src/so_utils.c \
		src/parsing.c	\
		src/so_utils2.c	\
		src/check_map_border.c	\
		src/check_map_contain.c	\
		src/key_hook.c			\
		src/player_move.c		\
		src/player_move2.c	\
		src/init.c \
		src/so_utils3.c \
		src/ft_check_var.c \
		src/ft_printf.c \
		src/ft_putc_s.c \
		src/ft_putd_i.c \
		src/ft_putx_X.c \


OBJ = ${SRC:%.c=%.o}

all: include/so_long.h ${NAME}

RM = rm -rf

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -L/Users/${USER}/Desktop/42/So_long/minilibx -lmlx -framework OpenGL -framework Appkit -o $(NAME) $(OBJ) -I$(I_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -g -o $@ -c $< -I$(I_DIR)

run: all
		./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re
