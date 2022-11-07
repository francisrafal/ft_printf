# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frafal <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 10:02:44 by frafal            #+#    #+#              #
#    Updated: 2022/11/07 10:03:12 by frafal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
LIBFTDIR	:= libft
LIBFT		:= libft.a
CC			:= cc
FLAGS		:= -Wall -Wextra -Werror
DEBUG		:=
SRCS		:= ft_printf.c ft_printf_hex.c ft_printf_utils.c
OBJS		:= ${SRCS:.c=.o}
RM	    	:= rm -f

%.o:		%.c
			@ ${CC} ${FLAGS} ${DEBUG} -c $< -o $@

${NAME}:	${OBJS} ${LIBFTDIR}/${LIBFT}
			@ echo "Compilation of $(NAME) ..."
			ar rcs ${LIBFT} ${OBJS}
			mv ${LIBFT} ${NAME}
			@ echo "$(NAME) created"

${LIBFTDIR}/${LIBFT}:
			make -C ${LIBFTDIR}
			cp ${LIBFTDIR}/${LIBFT} .

.PHONY:		all clean fclean re test

all:		${NAME}

clean:
			${RM} *.o
			make -C ${LIBFTDIR} clean
			@ echo "Deleting $(NAME) objects"

fclean:		clean
			${RM} ${NAME}
			make -C ${LIBFTDIR} fclean
			@ echo "Deleting $(NAME) library"

re:			fclean all

test:		all
			${CC} ${FLAGS} ${DEBUG} -o test main.c -L. -lftprintf
			./test
