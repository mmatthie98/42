NAME		=	test

SRC			=	ft_printf.c \
				ft_putc_s.c \
				ft_putd_i.c \
				ft_check_var.c \
				ft_putx_X.c \
				testprintf.c \

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
