# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frafal <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 20:59:46 by frafal            #+#    #+#              #
#    Updated: 2022/11/03 16:00:20 by frafal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
LIBFTDIR	:= libft
LIBFT		:= libft.a
CC			:= cc
FLAGS		:= -Wall -Wextra -Werror
DEBUG		:= -g
SRCS		:= ft_printf.c ft_printf_hex.c
OBJS		:= ${SRCS:.c=.o}
RM	    	:= rm -f

%.o:		%.c
			@ ${CC} ${FLAGS} ${DEBUG} -c $< -o $@

${NAME}:	${OBJS} ${LIBFT}
			@ echo "Compilation of $(NAME) ..."
			ar rcs ${LIBFT} ${OBJS}
			mv ${LIBFT} ${NAME}
			@ echo "$(NAME) created"

${LIBFT}:
			make -C ${LIBFTDIR}
			cp ${LIBFTDIR}/${LIBFT} .

.PHONY:		all clean fclean re test

all:		${NAME}

clean:
			${RM} *.o
			@ echo "Deleting $(NAME) objects"

fclean:		clean
			${RM} ${NAME}
			@ echo "Deleting $(NAME) library"

re:			fclean all

test:		all
			${CC} ${FLAGS} ${DEBUG} -o test main.c -L. -lftprintf -static
			./test
