SRCS	= convert_type.c convert_type2.c ft_printf.c fttoa.c libfunc.c utils.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

INCLUDE	= -I./includes

CC		= gcc
RM		= rm -f

AR		= ar rcs

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${AR} ${NAME} $?

all:		${NAME}
	
clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re libftprintf.a
