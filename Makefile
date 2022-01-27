NAME = get_next_line

OBJS =   ${SRCS:.c=.o}
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c\
        get_next_line_utils.c

.c.o:	${SRCS}
	${CC} ${CFLAGS} -c -o $@ $<

${NAME}:	${OBJS}
		ar rcs $(NAME) ${OBJS}

all:	${NAME}

bonus:	${OBJS_BONUS}
		ar rcs ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re