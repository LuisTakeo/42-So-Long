NAME = so_long
NAME_BONUS = so_long_bonus
LIBMLX = ./libs/MLX42

CC = cc
FLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBS = $(LIBMLX)/build/libmlx42.a
FLAGSMLX = -ldl -lglfw -pthread -lm

SRC = ./src/main.c
INCLUDES = -I includes -I $(LIBMLX)/include
OBJS = ${SRC:%.c=%.o}

all: libmlx $(NAME)

libmlx:
	@echo "Compilando lib gráfica..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES) && printf "Compilando: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

.PHONY: all, clean, fclean, re, libmlx
