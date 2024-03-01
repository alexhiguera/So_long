# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: columbux <columbux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 19:29:01 by ahiguera          #+#    #+#              #
#    Updated: 2024/03/01 17:36:46 by columbux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 		so_long
CFLAGS			= 		-Wall -Wextra -Werror

#   LIBFT
LIBFT_DIR		= 		./includes/Libft_2.0/
LIBFT			= 		$(LIBFT_DIR)/libft.a

#------------------------------------------------#
#   ASCII ART                                    #
CLR_RMV			:=		\033[0m
RED		    	:=		\033[1;31m
GREEN			:=		\033[1;32m
YELLOW			:=		\033[1;33m
BLUE			:=		\033[1;34m
CYAN 			:=		\033[1;36m
#------------------------------------------------#

ifeq ($(shell uname), Linux)
#   for LINUX
#	Install dependencies with `make dependencies`
	MLXFLAGS		= 		-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	SRC		 		= 		./test/test_map.c
	OBJ				= 		${SRC:.c=.o}

	MLX_DIR		 	= 		./includes/mlx_linux/
	MLX				= 		$(MLX_DIR)/libmlx.a
	
ifeq ($(shell uname), Darwin)
#   for MACos
	MLXFLAGS		= 		-framework OpenGL -framework AppKit -g -fsanitize=address
	SRC		 		= 		./src_macos/map.c
	OBJ				= 		${SRC:.c=.o}

	MLX_DIR		 	= 		./includes/mlx_macos/
	MLX_M			= 		$(MLX_DIR)/libmlx.a
	
else
# No suported OS
						@echo $(RED) "No OS detected"

endif


all:			$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(SRC)
						@echo $(YELLOW) "--> Compiling $(NAME) for Macos..."
						@gcc $(CFLAGS) $(MLXFLAGS) $(LIBFT) $(MLX) $(SRC) -o $(NAME)
						@echo $(GREEN)"So_long Compiled!"

$(LIBFT):
						@make -C $(LIBFT_DIR) all clean -s

$(MLX_linux):
						@make -C $(MLX_DIR) all -s
						@echo $(GRAY) "--> Making MLX"


clean:
						@make -C $(LIBFT_DIR) clean
						@make -C $(MLX_DIR) clean
						@make -C $(MLX_DIR) clean
						@rm -f $(OBJ)

fclean: 	clean
						@rm -f $(NAME)
						@make -C $(LIBFT_DIR) fclean
						@make -C $(MLX_DIR) fclean
						@make -C $(MLX_DIR) fclean

re: 		fclean all

norm:
						@echo $(YELLOW) "Norminette..."
						norminette $(SRC)
						@echo $(GREEN)"Norminette Done!"

dependencies:
						sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
						@echo $(GREEN)"Dependencies installed!"

wsl2:
						export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0
						@echo $(GREEN)"WSL configured!"

else

.PHONY: 	all clean fclean re $(LIBFT) $(MLX) norm dependencies wsl2
