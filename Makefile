# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 01:41:01 by dwanetta          #+#    #+#              #
#    Updated: 2021/04/26 13:02:16 by kgale            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
FLAGS = #-Wall -Wextra -Werror
LIB = -L mlx_mac  -L libft
OPTION_LIB = -lmlx -framework OpenGL -framework AppKit -lft
OPTION = -c
LIBFT = make -C libft
SRCS =	main.c\
		mlx/draw.c\
		parse/check_errors_with_file.c\
		parse/parser.c\
		parse/utils.c\
		parse/map_utils.c

OBJS_SRCS = ${SRCS:.c=.o}
OBJS =	$(OBJS_SRCS)

all: $(NAME)

$(NAME) : $(OBJS_SRCS)
		@$(CC) $(FLAGS) $(OPTION) $(SRCS)
		@$(LIBFT)
		@$(CC) $(LIB) $(OPTION_LIB) $(OBJS_SRCS) -o $(NAME)
clean:
		rm -f $(OBJS_SRCS)
		@$(LIBFT) clean
fclean: clean
		rm -f $(NAME)
		rm -f *.bmp
		@$(LIBFT) fclean
re: fclean all
.PHONY: all clean fclean re
