# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 11:06:31 by hsabouri          #+#    #+#              #
#    Updated: 2018/05/14 11:58:08 by hsabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##change header
NAME=ft_scop

LIBDIR=lib

LIBFTDIR=$(LIBDIR)/libft
LIBFTINC=$(LIBFTDIR)/includes

LIBGLFWDIR=$(LIBDIR)/GLFW/src
LIBGLFW=$(LIBDIR)/GLFW
LIBGLFWINC=$(LIBDIR)/GLFW/include

SRCNAM= main.c\
		first_draw.c

INCNAM= ft_scop.h\

SRCDIR= sources
INCDIR= includes
OBJDIR= objs

SRC= $(SRCNAM:%=$(SRCDIR)/%)
INC= $(INCNAM:%=$(INCDIR)/%)
OBJ= $(SRCNAM:%.c=$(OBJDIR)/%.o)

CFLAGS = -Wall -Wextra -DNON_COMPLETE
CC = clang
#CFLAGS += -Werror
CFLAGS += -g
CFLAGS += -I$(LIBFTINC) -I$(LIBGLFWINC) -I$(INCDIR)
LDFLAGS += -L$(LIBGLFWDIR)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
CFLAGS += -D LINUX `pkg-config --cflags glfw3` -Ilib/GLFW/deps/ -Ilib/GLFW/include/ 
LDFLAGS += `pkg-config --static --libs glfw3` -Ilib/GLFW/deps/ 
SPECIAL = lib/GLFW/deps/glad.c
endif
ifeq ($(UNAME_S),Darwin)
CFLAGS += -D OSX
LDFLAGS += -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
SPECIAL = 
endif

LDFLAGS += -L$(LIBFTDIR) -lft

all: libs $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(SPECIAL) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	mkdir -p objs
	$(CC) -o $@ -c $< $(CFLAGS)

libs:
	$(MAKE) -s -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -rf $(NAME)

re: fclean all
