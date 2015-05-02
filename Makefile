# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.make                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/02 05:42:29 by bsautron          #+#    #+#              #
#    Updated: 2015/05/02 09:15:32 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = arkanoid
SRC = main.c
DIR_H = ./includes
HEADER = $(DIR_H)/arkanoid.h \
		 $(DIR_H)/libft.h \
		 $(DIR_H)/get_next_line.h
OBJ = $(SRC:%.c=.obj/%.o)
	CFLAGS = -Wextra -Wall -Werror
	LIB = -L./libft -lft

.PHONY: all libs clean fclean re

all: dor libs $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LIB) -L./glfw-build/lib -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
	@echo "\033[32mReady!\033[0m"

dor:
	@mkdir .obj 2> /dev/null || env -i

libs:
	@make -C libft/
	@git submodule init
	@git submodule update
	@cd glfw ; cmake -DCMAKE_INSTALL_PREFIX=../glfw-build
	@make -C glfw install

.obj/%.o: %.c $(HEADER)
	@echo "\033[33m 	$<"
	@$(CC) -o $@ -I includes/ -I glfw-build/include/ -c $< -g

clean:
	rm -f $(OBJ)
	@rmdir .obj 2> /dev/null || env -i

fclean: clean
	rm -f $(NAME)

re: fclean all

