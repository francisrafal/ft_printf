# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frafal <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 20:59:46 by frafal            #+#    #+#              #
#    Updated: 2022/11/04 14:59:01 by frafal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
LIBFTDIR	:= libft
LIBFT		:= libft.a
CC			:= clang
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
			${CC} ${FLAGS} ${DEBUG} -fsanitize=address -o test main.c -L. -lftprintf
			./test
