# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: columbux <columbux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 19:29:01 by ahiguera          #+#    #+#              #
#    Updated: 2024/03/02 18:38:20 by columbux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 		so_long
CFLAGS			= 		-Wall -Wextra -Werror

#   LIBFT
LIBFT_DIR		= 		./includes/Libft_2.0/
LIBFT			= 		$(LIBFT_DIR)/libft.a

#------------------------------------------------------------------------------#
#   ASCII ART                                    							   #
CLR_RMV			:=		"\033[0m"
RED		    	:=		"\033[1;31m"
GREEN			:=		"\033[1;32m"
YELLOW			:=		"\033[1;33m"
BLUE			:=		"\033[1;34m"
CYAN 			:=		"\033[1;36m"
#______________________________________________________________________________#
#   OS DETECTION                                   							   #

ifeq ($(shell uname), Linux)
#   for LINUX                                   							   #
#	Install dependencies with `make dependencies`     						   #
	OS				=		Linux
	MLXFLAGS		= 		-L/usr/lib -lXext -lX11 -lm -lz
	SRC_DIR			=		./src_linux/
	MLX_DIR		 	= 		./includes/mlx_linux/
	MLX				= 		$(MLX_DIR)/libmlx.a
	
else ifeq ($(shell uname), Darwin)
#   for MACos                                   							   #
	OS				=		MacOS
	MLXFLAGS		= 		-framework OpenGL -framework AppKit -g -fsanitize=address
	SRC_DIR			=		./src_macos/
	MLX_DIR		 	= 		./includes/mlx_macos/
	MLX				= 		$(MLX_DIR)/libmlx.a
	
else
# No suported OS                                   							   #
	OS				=		Unknown
						@echo $(RED) "No OS detected"

endif
#______________________________________________________________________________#

SRC		 		= 		$(SRC_DIR)errors1.c 		\
						$(SRC_DIR)errors2.c 		\
						$(SRC_DIR)flood_fill.c 		\
						$(SRC_DIR)hooks.c 			\
						$(SRC_DIR)map_img.c 		\
						$(SRC_DIR)map.c 			\
						$(SRC_DIR)so_long.c 		\

OBJ				= 		${SRC:.c=.o}

all:			$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(SRC)
						@echo $(CYAN) "--> Compiling $(NAME) for $(OS)..."
						@gcc $(CFLAGS) $(MLXFLAGS) $(LIBFT) $(MLX) $(SRC) -o $(NAME)
						@echo $(GREEN)"So_long Compiled!"

$(LIBFT):
						@make -C $(LIBFT_DIR) all clean -s

$(MLX):
						@make -C $(MLX_DIR) all -s
						@echo $(GRAY) "--> Making MLX"


clean:
						@make -C $(LIBFT_DIR) clean
						@make -C $(MLX_DIR) clean
						@rm -f $(OBJ)

fclean: 	clean
						@rm -f $(NAME)
						@make -C $(LIBFT_DIR) fclean
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


.PHONY: 	all clean fclean re $(LIBFT) $(MLX) norm dependencies wsl2
