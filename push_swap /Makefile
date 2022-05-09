NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

L_DIR = ../libft

LIB = -lft

I_DIR = include

SRC =	src/parsing.c \
		src/parsing2.c \
		src/rotate.c	\
		src/rotate2.c	\
		src/low_sort.c	\
		src/low_sort2.c	\
		src/init.c		\
		src/make_int_tab.c	\
		src/ft_post_low_sort.c \
		src/post_low_sort2.c \

OBJ = ${SRC:%.c=%.o}

all: include/push_swap.h ${NAME}

RM = rm -rf

${NAME}: $(L_DIR)libft.a ${OBJ}
	${CC} ${CFLAGS} -g -o $(NAME) $(OBJ) -I$(I_DIR) -L$(L_DIR) $(LIB)

$(L_DIR)libft.a:
	make -C $(L_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -g -o $@ -c $< -I$(I_DIR)

clean:
		make clean -C $(L_DIR)
		rm -rf $(OBJ)

fclean: clean
		make fclean -C $(L_DIR)
		rm -rf $(NAME)

re: fclean all

.PHONY: all run clean fclean re
