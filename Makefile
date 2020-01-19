# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 14:46:44 by iporsenn          #+#    #+#              #
#    Updated: 2018/10/27 15:36:43 by iporsenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_scop

SRC_PATH = sources/
SRC_NAME =	main.c

SRC =  $(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDE_PATH = includes/
INCLUDE_NAME = scop.h
INCLUDE = $(addprefix $(INCLUDE_PATH), $(INCLUDE_NAME))

LIB_PATH = ./lib

LIBFT_PATH = $(LIB_PATH)/libft/

GLFW_PATH = $(LIB_PATH)/glfw/src/

OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

FLAGS = -Wall -Werror -Wextra -g3
# -fsanitize=address
LFLAGS = -L$(GLFW_PATH) -L$(LIBFT_PATH)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
CFLAGS += -D LINUX `pkg-config --cflags glfw3` 
FLAGS_LIB += `pkg-config --static --libs glfw3`
# SPECIAL = lib/GLFW/deps/glad.c
endif
ifeq ($(UNAME_S),Darwin)
CFLAGS += -D OSX
FLAGS_LIB += -lft -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
# SPECIAL = 
endif

# `pkg-config --cflags glfw3` -o myprog myprog.c `pkg-config --static --libs glfw3`

.PHONY: all, build, creadir, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@make -C lib/libft
	@gcc $(FLAGS) $(LFLAGS) $(FLAGS_LIB) $(SRC) -o $(NAME)
	@echo "\033[32mExe built\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -o $@ -c $< $(CFLAGS)

build :
	@gcc $(FLAGS) $(LFLAGS) $(FLAGS_LIB) $(SRC) -o $(NAME)
	@echo "\033[32mExe built\033[0m"

clean:
	@make clean -C lib/libft
	@rm -rf $(OBJ_PATH)
	@echo "\033[31m.o cleaned\033[0m"

fclean: clean
	@make fclean -C lib/libft
	@rm -f $(NAME)
	@echo "\033[31mAll cleaned\033[0m"

re: fclean all
