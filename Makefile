# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frafal <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 20:59:46 by frafal            #+#    #+#              #
#    Updated: 2022/11/01 14:50:51 by frafal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
LIBFTDIR	:= libft
LIBFT		:= libft.a
CC			:= cc
FLAGS		:= -Wall -Wextra -Werror
SRCS		:= ft_printf.c
OBJS		:= ${SRCS:.c=.o}
RM	    	:= rm -f

%.o:		%.c
			@ ${CC} ${FLAGS} -c $< -o $@

${NAME}:	${OBJS} ${LIBFT}
			@ echo "Compilation of $(NAME) ..."
			@ ar rcs ${LIBFT} ${OBJS}
			@ mv ${LIBFT} ${NAME}
			@ echo "$(NAME) created"

${LIBFT}:
			@ make -C ${LIBFTDIR}
			@ cp ${LIBFTDIR}/${LIBFT} .

.PHONY:		all clean fclean re so

all:		${NAME}

clean:
			@ ${RM} *.o
			@ echo "Deleting $(NAME) objects"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "Deleting $(NAME) library"

re:			fclean all
