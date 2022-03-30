NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

L_DIR =  libft

LIB = -lft

I_DIR = include

SRC =	parsing.c \
		parsing2.c \
		rotate.c	\
		rotate2.c	\
		low_sort.c	\
		low_sort2.c	\
		init.c		\

OBJ = ${SRC:%.c=%.o}

all: include/push_swap.h ${NAME}

RM = rm -rf

${NAME}: $(L_DIR)/libft.a ${OBJ}
	${CC} ${CFLAGS} -g -o $(NAME) $(OBJ) -I$(I_DIR) -L$(L_DIR) $(LIB)

$(L_DIR)/libft.a:
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


