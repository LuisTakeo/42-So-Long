NAME = so_long
NAME_BONUS = so_long_bonus
LIBS_FOLDER = ./lib
LIBMLX = $(LIBS_FOLDER)/MLX42
LIBFT = $(LIBS_FOLDER)/libft

CC = cc
FLAGS = -Wextra -Wall -Werror
FLAGSOMLX = -Wunreachable-code -Ofast
LIBS = $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a
FLAGSMLX = -ldl -lglfw -pthread -lm

SRC = ./src/main.c \
	 ./src/hooks.c
INCLUDES = -I includes -I $(LIBMLX)/include -I $(LIBFT)/libft.h -I $(LIBFT)/gnl/includes -I $(LIBFT)/ft_printf/includes
OBJS = ${SRC:%.c=%.o}

all: libmlx libft $(NAME)
	@echo "Concluido!"

libmlx:
	@echo "Compilando lib gráfica..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 --no-print-directory

libft:
	@echo "Compilando Libft..."
	@make all bonus new_fun -C $(LIBFT) $(FLAGS) --no-print-directory

%.o: %.c
	@$(CC) $(FLAGS) $(FLAGSOMLX) -o $@ -c $< $(INCLUDES) && echo "Compilando: $(notdir $<)"

$(NAME): $(OBJS)
	@echo "Criando arquivo $(NAME)"
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME) $(FLAGSMLX)

clean:
	@echo "Limpando objects..."
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT) --no-print-directory
	@echo "Limpando build..."
	@rm -rf $(LIBMLX)/build
	@echo "Feito!"


fclean: clean
	@echo "Removendo libft.a..."
	@make fclean -C $(LIBFT) --no-print-directory
	@echo "Removendo executável..."
	@rm -rf $(NAME)
	@echo "Feito!"

.PHONY: all, clean, fclean, re, libmlx
