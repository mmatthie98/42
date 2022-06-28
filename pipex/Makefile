NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g  

I_DIR = include

L_DIR = ../libft

SRC = 	parsing.c \
		parsing2.c \
		utils.c	\
		utils2.c \
		utils3.c \
		
OBJ = ${SRC:%.c=%.o}

all : include/pipex.h ${NAME}

RM = rm -rf

${NAME}: ${L_DIR}/libft.a ${OBJ}
	${CC} ${CFLAGS} -o $(NAME) ${OBJ} -I$(I_DIR) -L$(L_DIR) $(LIB) -lft

$(L_DIR)/libft.a:
	make -j -C $(L_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR)

clean:
		make clean -C $(L_DIR)
		rm -rf $(OBJ)

fclean: clean
		make fclean -C $(L_DIR)
		rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
