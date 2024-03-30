# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 19:29:01 by ahiguera          #+#    #+#              #
#    Updated: 2024/03/30 21:06:29 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
MLX_CF		:= -framework OpenGL -framework AppKit
CFLAGS		:= -Wall -Wextra -Werror -Iincludes/Libft_2.0/
CLEANFLAGS	:= -g -fsanitize=address
MLX_PATH	:= includes/mlx_macos
LIBFT_PATH	:= includes/Libft_2.0/
SRC_MACOS	:=	src_macos/
SRC 		:= 	$(SRC_MACOS)charge_img.c 	$(SRC_MACOS)errors.c	\
				$(SRC_MACOS)flood_fill.c 	$(SRC_MACOS)getmap.c 	\
				$(SRC_MACOS)keys.c 			$(SRC_MACOS)so_long.c	\
				$(SRC_MACOS)put_things.c 	$(SRC_MACOS)read_map.c	\
				$(SRC_MACOS)utils.c

all:$(NAME)

$(NAME): 	$(SRC)
				mkdir -p bin
				make -C $(MLX_PATH) 2>/dev/null 
				make -C $(LIBFT_PATH)
				mv $(MLX_PATH)/libmlx.a bin/
				mv $(LIBFT_PATH)libft.a bin/
				gcc $(CFLAGS) $(CLEANFLAGS) $(MLX_CF) bin/libmlx.a bin/libft.a $(SRC) -o $(NAME) 

clean:
				rm -rf $(OBJ)
				make -C $(LIBFT_PATH) clean
				make -C $(MLX_PATH) clean
				rm -rf obj

fclean: 	clean
				rm -rf $(NAME)
				rm -rf bin

re: 		fclean all

norm:
						@echo $(YELLOW) "Norminette..."
						norminette $(SRC)
						@echo $(GREEN)"Norminette Done!"

.PHONY: 	all clean fclean re $(LIBFT) $(MLX) norm dependencies wsl2
