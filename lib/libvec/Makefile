# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 15:52:46 by iporsenn          #+#    #+#              #
#    Updated: 2020/03/07 17:23:20 by iporsenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec.a

SRC_PATH = src/
SRC_NAME =	vec_new.c		\
			vec_add.c		\
			vec_sub.c		\
			vec_dot_al.c	\
			vec_dot_gem.c	\
			vec_normalize.c	\
			vec_cross.c		\
			vec_scale.c

SRC =  $(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDE_PATH = ./include
INCLUDE_NAME = libvec.h
INCLUDE = $(addprefix $(INCLUDE_PATH), $(INCLUDE_NAME))

OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

FLAGS = -Wall -Werror -Wextra -g -I$(INCLUDE_PATH)

all: $(NAME)

$(NAME):	creadir $(OBJ)
	@echo "\033[32mLibft built\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -o $@ -c $<

creadir:
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mLibft cleaned\033[0m"

re: fclean all
