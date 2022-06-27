SRC	= ./source/*.c

NAME	= bsq

INCDIR	= ./header/

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -g

RM	= rm -f

.c.o:
	@${CC} ${CFLAGS} -I${INCDIR} -c $< -o ${<:.c=.o}

${NAME}:	${SRC}
	@${CC} ${CFLAGS} -o ${NAME} ${SRC}

all:	${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
