NAME = so_long
NAME_BONUS = so_long_bonus
LIBS_FOLDER = ./lib
LIBMLX = $(LIBS_FOLDER)/MLX42

CC = cc
FLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBS = $(LIBMLX)/build/libmlx42.a
FLAGSMLX = -ldl -lglfw -pthread -lm

SRC = ./src/main.c
INCLUDES = -I includes -I $(LIBMLX)/include
OBJS = ${SRC:%.c=%.o}

all: libmlx $(NAME)
	@echo "Concluido!"

libmlx:
	@echo "Compilando lib gráfica..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES) && echo "Compilando: $(notdir $<)"

$(NAME): $(OBJS)
	@echo "Criando arquivo $(NAME)"
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME) $(FLAGSMLX)

clean:
	@echo "Limpando objects..."
	@rm -rf $(OBJS)
	@echo "Feito!"
	@echo "Limpando build..."
	@rm -rf $(LIBMLX)/build
	@echo "Feito!"


fclean: clean
	@echo "Removendo executável..."
	@rm -rf $(NAME)
	@echo "Feito!"

.PHONY: all, clean, fclean, re, libmlx
