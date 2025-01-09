# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 08:48:03 by dteruya           #+#    #+#              #
#    Updated: 2025/01/09 11:30:14 by dteruya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = -L/usr/local/lib -lmlx
LIBS = -lXext -lX11 -lm

LIBFT = ./libft/libft.a

SRC = fdf.c\

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./libft -I./gnl

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o aa $(OBJ) $(LIBFT) $(LIBS) $(MLX)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f aa

re: fclean all
