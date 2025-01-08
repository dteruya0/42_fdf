# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 08:48:03 by dteruya           #+#    #+#              #
#    Updated: 2025/01/07 13:53:50 by dteruya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = -L/usr/local/lib -lmlx
LIBS = -lXext -lX11 -lm

PRINTF = ./printf/libftprintf.a
LIBFT = ./libft/libft.a
GNL = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

SRC = fdf.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./libft -I./gnl

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o aa $(OBJ) $(LIBFT) $(PRINTF) $(LIBS) $(MLX)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f aa

re: fclean all
