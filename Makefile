NAME = so_long
NAME_BONUS = so_long_bonus
LIBS_FOLDER = ./lib
LIBMLX = $(LIBS_FOLDER)/MLX42
LIBFT = $(LIBS_FOLDER)/libft
HEADERS = ./includes/so_long.h ./includes/so_long_bonus.h

CC = cc
FLAGS = -Wextra -Wall -Werror
FLAGSOMLX = -Wunreachable-code -Ofast
LIBS = $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a
FLAGSMLX = -ldl -lglfw -pthread -lm

SRC = ./src/main.c \
	 ./src/hooks.c \
	 ./src/generate_map.c \
	 ./src/init_game.c \
	 ./src/init_image.c \
	 ./src/img_screen.c \
	 ./src/img_ingame.c \
	 ./src/finish_game.c \
	 ./src/update_map.c \
	 ./src/pre_validation.c \
	 ./src/flood_fill.c \
	 ./src/char_valid.c \
	 ./src/utils.c

SRC_BONUS = ./src_bonus/main_bonus.c \
	 ./src_bonus/hooks_bonus.c \
	 ./src_bonus/generate_map_bonus.c \
	 ./src_bonus/init_game_bonus.c \
	 ./src_bonus/init_image_bonus.c \
	 ./src_bonus/img_screen_bonus.c \
	 ./src_bonus/img_ingame_bonus.c \
	 ./src_bonus/finish_game_bonus.c \
	 ./src_bonus/update_map_bonus.c \
	 ./src_bonus/pre_validation_bonus.c \
	 ./src_bonus/flood_fill_bonus.c \
	 ./src_bonus/char_valid_bonus.c \
	 ./src_bonus/utils_bonus.c \
	 ./src_bonus/animation_char_bonus.c \
	 ./src_bonus/init_player_img_bonus.c \
	 ./src_bonus/count_screen_bonus.c \
	 ./src_bonus/init_enemies_bonus.c
INCLUDES = -I includes -I $(LIBMLX)/include -I $(LIBFT)/ -I $(LIBFT)/gnl/includes -I $(LIBFT)/ft_printf/includes
OBJS = ${SRC:%.c=%.o}
OBJS_BONUS = ${SRC_BONUS:%.c=%.o}

all: libmlx libft $(NAME)
	@echo "Concluido!"

bonus: libmlx libft $(NAME_BONUS)

libmlx:
	@echo "Compilando lib gráfica..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 --no-print-directory

libft:
	@echo "Compilando Libft..."
	@make all bonus new_fun -C $(LIBFT) $(FLAGS) --no-print-directory

%.o: %.c $(HEADERS)
	@$(CC) $(FLAGS) $(FLAGSOMLX) -o $@ -c $< && echo "Compilando: $(notdir $<)"

$(NAME): $(OBJS)
	@echo "Criando arquivo $(NAME)"
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME) $(FLAGSMLX)

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "Criando arquivo $(NAME)"
	@$(CC) $(OBJS_BONUS) $(LIBS) $(INCLUDES) -o $(NAME_BONUS) $(FLAGSMLX)

clean:
	@echo "Limpando objects..."
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@make clean -C $(LIBFT) --no-print-directory
	@echo "Limpando build..."
	@rm -rf $(LIBMLX)/build
	@echo "Feito!"


fclean: clean
	@echo "Removendo libft.a..."
	@make fclean -C $(LIBFT) --no-print-directory
	@echo "Removendo executável..."
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "Feito!"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
