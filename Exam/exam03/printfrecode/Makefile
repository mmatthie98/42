NAME		=	libftprintf.a

SRC			=	printf.c \

OBJ		=	${SRC:.c=.o}

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
