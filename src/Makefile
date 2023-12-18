# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 19:29:01 by ahiguera          #+#    #+#              #
#    Updated: 2023/12/18 17:43:25 by ahiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit 

NAME = so_long
SRC = ../test/test_open_window.c
INCLUDE = so_long.h

MLX_DIR = ../includes/minilibx
MLX = $(MLX_DIR)/libmlx.a

#libft:
#    make all clean -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(MLX) $(SRC) $(INCLUDE)
	gcc $(CFLAGS) $(SRC) $(MLX) -o $(NAME)

$(MLX):
	make -s -C $(MLX_DIR) all

clean:
	rm -f $(NAME) $(MLX)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re