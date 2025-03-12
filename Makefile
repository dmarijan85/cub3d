# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 14:39:35 by mclaver-          #+#    #+#              #
#    Updated: 2025/03/12 16:23:53 by dmarijan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME = cub3D

# Dirs
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libs/libft
MLX42_DIR = libs/MLX42
INCLUDE_DIRS = -I. -I$(LIBFT_DIR) -I$(MLX42_DIR)/include

# Source Files
SRC_FILES = src/main.c			\
			src/waterbucket.c	\
			src/minecraft.c		\
			src/xrayzzzz.c		\
			src/picturethis.c	\
			src/iminyourwalls.c	\
			src/jarvishookthis.c\
			src/custommath.c	\
			src/moves.c			\
			src/moves_utils.c	\
			src/pmovement.c		\
			src/utils.c			\
			src/map_utils.c		\
			src/freemyman.c		\
			src/parser_utils.c

HEADERS =	src/cub3d.h

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libs
LIBFT = $(LIBFT_DIR)/libft.a
MLX42 = build/libmlx42.a

# Compiler and flags
CC = gcc
MLXFLAGS = -Ilibs/MLX42/include -ldl -lglfw -pthread -lm
CFLAGS = -ffast-math -Wall -Werror -Wextra -Ofast -no-pie -g -fsanitize=address

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADERS) $(LIBFT) $(MLX42) Makefile
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MLX42) $(MLXFLAGS) -o $(NAME)
	@echo "Executable cub3d created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@
	@echo "Compiled $< to $@"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
	@cmake $(MLX42_DIR) -B build
	@cmake --build build -j4

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf build
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned objects"

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "Full clean done"

re: fclean all

.PHONY: all clean fclean re
