NAME		=	gnl

SRC			=	get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				maingnl.c \

OBJ		=	${SRC:.c=.o}

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

$(NAME):	$(OBJ)
		${CC} ${CFLAGS} -o $@ $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
