# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 15:20:12 by kgale             #+#    #+#              #
#    Updated: 2021/02/05 15:26:28 by kgale            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = gcc
FLAGS = -Wall -Werror -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -L libft -lft -03
LIBFT = libft
SRCS =		main.c	\
			parse/parser.c	\
			parse/check_errors_with_file.c

all:		$(NAME)

libft:		
			@make -C $(LIBFT)

$(NAME):	libft
			$(CC) $(FLAGS) $(OPTION) $(SRCS)
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

clean:

fclean:		clean

re:			fclean all

.PHONY:	all clean fclean re