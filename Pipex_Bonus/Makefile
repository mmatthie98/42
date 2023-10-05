NAME = pipex_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

I_DIR = include

L_DIR = ../libft

SRC = 	parsing_bonus.c \
		parsing2_bonus.c \
		utils_bonus.c	\
		utils2_bonus.c \
		utils3_bonus.c \
		
OBJ = ${SRC:%.c=%.o}

all : include/pipex_bonus.h ${NAME}

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
