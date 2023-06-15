# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 22:54:55 by nbeaufil          #+#    #+#              #
#    Updated: 2023/06/15 23:17:26 by nbeaufil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_split.c				\
			srcs/utils.c				\
			srcs/wildcard.c				\
			srcs/wildcard_check.c		\
			srcs/wildcard_ext.c			\
			srcs/wildcard_utils.c

NAME	=	libwildcard.a
OBJS	=	${SRCS:.c=.o}

CC		=	gcc
INCLUDE	=	-I ./include
FLAGS	=	-Wall -Wextra -Werror -g3
BUGS	=	-fsanitize=address -g3

.c.o:
	${CC} ${FLAGS} -c $< ${INCLUDE} -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

test:	${NAME}
	${CC} ${FLAGS} ${INCLUDE} test.c -c -o test.o
	${CC} ${FLAGS} test.o -L. -lwildcard ${INCLUDE} -o test

clean:
	rm -f ${OBJS}
	rm -f test.o

fclean:	clean
	rm -f ${NAME}
	rm -f test

re : fclean all

.PHONY:	re fclean clean all

.SILENT:
