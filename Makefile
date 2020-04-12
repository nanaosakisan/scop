# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 11:03:17 by iporsenn          #+#    #+#              #
#    Updated: 2020/04/11 19:02:46 by iporsenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_scop

LIB_DIR = lib

LIBFT_DIR = $(LIB_DIR)/libft
LIBFT_INC = $(LIBFT_DIR)/include

LIBVEC_DIR = $(LIB_DIR)/libvec
LIBVEC_INC = $(LIBVEC_DIR)/include

LIB_GLFW = $(LIB_DIR)/GLFW
LIBGLFW_DIR = $(LIB_GLFW)/src
LIBGLFW_INC = $(LIB_DIR)/GLFW/include

SRC_NAME =	main.c				\
			init.c				\
			init_matrice.c		\
			draw.c				\
			load_shaders.c		\
			parsing.c			\
			parsing_tool.c		\
			matrice_al.c		\
			transformation.c	\
			event.c

INC_NAME = ft_scop.h	\

SRC_DIR = sources
INC_DIR = includes
OBJ_DIR = objs

SRC = $(SRC_NAME:%=$(SRC_DIR)/%)
INC = $(INC_NAME:%=$(INC_DIR)/%)
OBJ = $(SRC_NAME:%.c=$(OBJ_DIR)/%.o)

C_FLAGS = -Wall -Wextra -DNON_COMPLETE
CC = clang
#C_FLAGS += -Werror
C_FLAGS += -g
C_FLAGS += -I$(LIBFT_INC) -I$(LIBVEC_INC) -I$(LIBGLFW_INC) -I$(INC_DIR)
LD_FLAGS += -L$(LIBGLFW_DIR)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
C_FLAGS += -D LINUX `pkg-config --cflags glfw3` -Ilib/GLFW/deps/ -Ilib/GLFW/include/
LD_FLAGS += `pkg-config --static --libs glfw3` -Ilib/GLFW/deps/
SPECIAL = lib/GLFW/deps/glad.c
endif
ifeq ($(UNAME_S),Darwin)
C_FLAGS += -D OSX
LD_FLAGS += -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
SPECIAL =
endif

LD_FLAGS += -L$(LIBFT_DIR) -lft -L$(LIBVEC_DIR) -lvec

all: libs $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(SPECIAL) $(LD_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	mkdir -p objs
	$(CC) -o $@ -c $< $(C_FLAGS)

libs:
	$(MAKE) -s -C $(LIBFT_DIR)
	$(MAKE) -s -C $(LIBVEC_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBVEC_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBVEC_DIR) fclean
	rm -rf $(NAME)

re: fclean all
