# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 08:48:03 by dteruya           #+#    #+#              #
#    Updated: 2025/02/26 14:08:55 by dteruya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_BONUS = fdf_bonus

CC 			= cc
CFLAGS		= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LDFLAGS		= -L/usr/local/lib -lmlx -lXext -lX11 -lm
INCLUDES	= -I ./src -I ./libft

LIBFT_DIR	= lib/libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

SRC = src/main.c \
		src/file_format.c \
		src/read_file.c \
		src/fdf_utils.c \
		src/bresenhams.c \
		src/coordinate_utils.c \

SRC_BONUS = src_bonus/main_bonus.c \
			src_bonus/file_format_bonus.c \
			src_bonus/read_file_bonus.c \
			src_bonus/fdf_utils_bonus.c \
			src_bonus/bresenham_bonus.c \
			src_bonus/coordinate_utils_bonus.c \

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
DEPS = ./src/fdf.h
DEPS_BONUS = ./src_bonus/fdf_bonus.h

all: libft $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(LDFLAGS)

bonus: libft $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT_LIB) $(LDFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "compiling $<"

libft:
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re libft
