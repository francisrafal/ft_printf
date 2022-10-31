# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frafal <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 20:59:46 by frafal            #+#    #+#              #
#    Updated: 2022/10/31 13:40:31 by frafal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
LIBFT		:= libft
CC			:= cc
FLAGS		:= -Wall -Wextra -Werror
SRCS		:= ft_printf.c
OBJS		:= ${SRCS:.c=.o}
RM	    	:= rm -f

%.o:		%.c
			@ ${CC} ${FLAGS} -c $< -o $@

${NAME}:	${OBJS}
			@ echo "Compilation of $(NAME) ..."
			@ ar rcs ${NAME} ${OBJS}
			@ echo "$(NAME) created"

libft:
			@ make -C ${LIBFT}

.PHONY:		all clean fclean re so

all:		${NAME}

clean:
			@ ${RM} *.o
			@ echo "Deleting $(NAME) objects"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "Deleting $(NAME) library"

re:			fclean all
