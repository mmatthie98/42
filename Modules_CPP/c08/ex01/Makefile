NAME	= Span

SRCS	= 	Span.cpp \
			main.cpp \

CC		= c++
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME):	${SRCS}
			${CC} ${CFLAGS} ${SRCS} -o $@

all:	${NAME}

clean:
		${RM} ${NAME}

fclean:
		${RM} ${NAME}

re:		clean all

.PHONY:	all clean re
