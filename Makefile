BIN = scope
LIBFT_DIR = lib/libft
# LIBTGA_DIR = lib/libtga
# LIBVEC_DIR = lib/libvec

NO_COLOR=\x1b[0m
GREEN=\x1b[32;01m
YELLOW=\x1b[33;01m
BLUE=\x1b[36;01m
BLINK=\x1b[5;01m

# -----------------
# SOURCE FILES (.c)
# Don't forget to list files at the end of the project
# -----------------

SRCS_FILES = $(shell find srcs -name "*.c")

# -----------------

SRCS_DIR = srcs
SRCS = $(SRCS_FILES:%=%)

# -----------------
# HEADER FILES (.h)
# Don't forget to list files at the end of the project
# -----------------

INCS_FILES = $(shell find includes -name "*.h")

# -----------------

INCS_DIR = includes
INCS = $(INCS_FILES:%=%)

# -----------------

OBJS_DIR = objs
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# -----------------

CC = clang
CFLAGS = -Wall -Wextra -Iincludes
CFLAGS += -g
#CFLAGS += -O3 -march=native
#CFLAGS += -Werror

ifeq ($(SAN), yes)
LDFLAGS = -fsanitize=address
CFLAGS += -fsanitize=address
endif

ifeq ($(OPT), yes)
CFLAGS += -O3 -march=native
endif

CFLAGS += -I$(LIBFT_DIR)/includes
# CFLAGS += -I$(LIBVEC_DIR)/includes
# CFLAGS += -I$(LIBTGA_DIR)/includes
CFLAGS += -I.

LDFLAGS += -L$(LIBFT_DIR) -lft
LDFLAGS += -lpthread -ldl -lm
# LDFLAGS += -L$(LIBVEC_DIR) -lvec
# LDFLAGS += -L$(LIBTGA_DIR) -ltga

all: message libft libvec libtga $(BIN)

message:
	@echo -e "$(YELLOW)" "[BUILD]" "$(NO_COLOR)" $(BIN)

libft:
	@echo -e "$(YELLOW)" "[BUILD]" "$(NO_COLOR)" $@
	@$(MAKE) -j -s -C $(LIBFT_DIR) SAN=$(SAN) OPT=$(OPT)

libvec:
	@echo -e "$(YELLOW)" "[BUILD]" "$(NO_COLOR)" $@
	@$(MAKE) -j -s -C $(LIBVEC_DIR) SAN=$(SAN) OPT=$(OPT)

libtga:
	@echo -e "$(YELLOW)" "[BUILD]" "$(NO_COLOR)" $@
	@$(MAKE) -j -s -C $(LIBTGA_DIR) SAN=$(SAN) OPT=$(OPT)

$(BIN): $(OBJS)
	@echo -e "$(BLUE)" "[LINK]" "$(NO_COLOR)" $@
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo -e "$(BLINK)" "FINISHED !" "$(NO_COLOR)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS)
	@echo -e "$(GREEN)" "[COMPILE]" "$(NO_COLOR)" $<
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(LIBVEC_DIR) clean
	@$(MAKE) -s -C $(LIBTGA_DIR) clean

fclean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(LIBVEC_DIR) fclean
	@$(MAKE) -s -C $(LIBTGA_DIR) fclean
	rm -rf $(BIN)

re: fclean
	@$(MAKE) all

.PHONY: clean fclean libft libvec libtga re all

.SILENT: clean fclean libft libvec libtga re all