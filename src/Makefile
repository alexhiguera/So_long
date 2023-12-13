# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 19:29:01 by ahiguera          #+#    #+#              #
#    Updated: 2023/12/13 16:22:02 by ahiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
INCLUDE = so_long.h
CFLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit 
#-Whon Deprecated
LIBFT_DIR = ../includes/libft
MLX_DIR = ../includes/includes/minilibx/mlx

SRC = ../test/test_open_window.c

#libft:
#    make all clean -C $(LIBFT_DIR)

$(NAME): 
	gcc $(CFLAGS) $(SRC) -o $(NAME)

MLX = $(MLX_DIR)/libmlx.a

all: $(NAME) $(MLX)

clean:
	rm -f $(NAME) $(MLX)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re