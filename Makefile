# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 08:48:03 by dteruya           #+#    #+#              #
#    Updated: 2025/01/20 14:44:46 by dteruya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = -L/usr/local/lib -lmlx
LIBS = -lXext -lX11 -lm

LIBFT = ./libft/libft.a

SRC = fdf.c fdf_utils.c\

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./libft -I./gnl

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o fdf $(OBJ) $(LIBFT) $(LIBS) $(MLX)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f fdf

re: fclean all
