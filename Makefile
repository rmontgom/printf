# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmontgom <rmontgom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 12:25:35 by rmontgom          #+#    #+#              #
#    Updated: 2021/12/02 17:31:30 by rmontgom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_ut.c

HEADER = ft_printf.h

OBJS = ${SRCS:%.c=%.o}

CC = clang
CFLAGS = -Wall -Wextra -Werror -I ${HEADER}

.PHONY : all clean fclean re

all : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	ar -rcs ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ 

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all