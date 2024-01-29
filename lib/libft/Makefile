# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 18:38:35 by tpaim-yu          #+#    #+#              #
#    Updated: 2024/01/10 19:56:07 by tpaim-yu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
HEADER = ./
FLAGS = -Wall -Werror -Wextra
SRC = ft_isdigit.c \
				 ft_isalpha.c \
				 ft_isalnum.c \
				 ft_isascii.c \
				 ft_isprint.c \
				 ft_strlen.c \
				 ft_memset.c \
				 ft_bzero.c \
				 ft_memcpy.c \
				 ft_memmove.c \
				 ft_strlcpy.c \
				 ft_strlcat.c \
				 ft_toupper.c \
				 ft_tolower.c \
				 ft_strchr.c \
				 ft_strrchr.c \
				 ft_strncmp.c \
				 ft_memchr.c \
				 ft_memcmp.c \
				 ft_strnstr.c \
				 ft_atoi.c \
				 ft_calloc.c \
				 ft_strdup.c \
				 ft_substr.c \
				 ft_putchar_fd.c \
				 ft_putstr_fd.c \
				 ft_putendl_fd.c \
				 ft_putnbr_fd.c \
				 ft_striteri.c \
				 ft_strmapi.c \
				 ft_strjoin.c \
				 ft_strtrim.c \
				 ft_itoa.c \
				 ft_split.c \
				 ft_putnull_fd.c

SRC_BONUS = ft_lstnew_bonus.c \
				 ft_lstadd_front_bonus.c \
				 ft_lstsize_bonus.c \
				 ft_lstlast_bonus.c \
				 ft_lstadd_back_bonus.c \
				 ft_lstdelone_bonus.c \
				 ft_lstclear_bonus.c \
				 ft_lstiter_bonus.c \
				 ft_lstmap_bonus.c

SRC_NEW_FUN = gnl/get_next_line.c \
				 gnl/get_next_line_utils.c \
				 ft_printf/ft_printf.c \
				 ft_printf/ft_init_flags.c \
				 ft_printf/ft_putnbrbase_fd.c \
				 ft_printf/ft_putpointer_fd.c \
				 ft_printf/ft_putstrspc_fd.c \
				 ft_printf/ft_putunsnbr_fd.c

OBJ = ${SRC:%.c=%.o}
OBJ_BONUS = ${SRC_BONUS:%.c=%.o}
OBJ_NEW_FUN = ${SRC_NEW_FUN:%.c=%.o}

${NAME}: ${OBJ}

all: ${NAME}
	@echo "Arquivos da Libft compilados com sucesso!"

bonus: ${OBJ_BONUS}
	@echo "Arquivos bonus compilados com sucesso!"

new_fun: ${OBJ_NEW_FUN}
	@echo "Funções adicionais adicionadas com sucesso!"

clean:
	@echo "Limpando objetos da Libft..."
	@rm -f ${OBJ} ${OBJ_BONUS}
	@echo "Limpando objetos da GNL/ft_printf..."
	@rm -f ${OBJ_NEW_FUN}
	@echo "Feito!"

fclean: clean
	@echo "Removendo $(NAME)..."
	@rm -f ${NAME}
	@echo "Feito!"

re: fclean all

%.o: %.c
	@echo "Compilando $(notdir $<) ..."
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)
	@ar rcs ${NAME} $@

.PHONY: bonus all clean fclean re
