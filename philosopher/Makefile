NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g  -pthread

SRC = 	philosopher.c	\
		parsing.c		\
		parsing2.c		\

OBJ = ${SRC:%.c=%.o}

all : philo.h ${NAME}

RM = rm -rf

${NAME}: ${OBJ}
	${CC} ${CFLAGS} -o $(NAME) ${OBJ}

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
