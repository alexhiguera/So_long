# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 19:29:01 by ahiguera          #+#    #+#              #
#    Updated: 2024/04/04 17:37:19 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#████████████████████████████ Configuration ███████████████████████████████████#
NAME			:= so_long
CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror -Iincludes/Libft_2.0/
LIBFT			:= includes/Libft_2.0/
BIN				:= bin/

#██████████████████████████████ Colors ████████████████████████████████████████#
DEF_COLOR 		=	\033[0;39m
GRAY 			=	\033[0;90m
RED 			=	\033[0;91m
GREEN 			=	\033[0;92m
YELLOW 			=	\033[0;93m
BLUE 			=	\033[0;94m
MAGENTA 		=	\033[0;95m
CYAN 			=	\033[0;96m
WHITE 			=	\033[0;97m

#█████████████████████████ SO properties ███████████████████████████████████████#

ifeq ($(shell uname), Linux)
#   for LINUX                                   							   #
#	Install dependencies with `make dependencies`     						   #
	OS				=		Linux
	MLXFLAGS		= 		-L/usr/lib -lXext -lX11 -lm -lz
	SRC_DIR			=		./src_linux/
	MLX			 	= 		./includes/mlx_linux/
	
else ifeq ($(shell uname), Darwin)
#   for MACos                                   							   #
	OS				=		MacOS
	MLXFLAGS		= 		-framework OpenGL -framework AppKit
	CLEANFLAGS		=		-g -fsanitize=address
	SRC_DIR			=		./src_macos/
	MLX			 	= 		./includes/mlx_macos/
	
else
# No suported OS                                   							   #
	OS				=		Unknown
						@echo $(RED) "No OS detected"

endif

#█████████████████████████████ SOURCES █████████████████████████████████████████#

SRC 		:= 	$(SRC_DIR)sprites.c 	$(SRC_DIR)errors.c		\
				$(SRC_DIR)flood_fill.c 	$(SRC_DIR)getmap.c 		\
				$(SRC_DIR)keys.c 		$(SRC_DIR)so_long.c		\
				$(SRC_DIR)puts.c 		$(SRC_DIR)read_map.c	\

#████████████████████████████ Rules ████████████████████████████████████████████#
all:$(NAME)

$(NAME): 	$(SRC)
				@echo "$(CYAN)Compiling $(NAME) for $(OS)...$(WHITE)\n"
				@mkdir -p bin
				@make -C $(MLX) 2>/dev/null 
				@make -C $(LIBFT)
				@mv $(MLX)/libmlx.a bin/
				@mv $(LIBFT)libft.a bin/
				@$(CC) $(CFLAGS) $(MLXFLAGS) $(CLEANFLAGS) $(BIN)* $(SRC) -o $(NAME)
				@echo "$(GREEN)So_long Compiled! 🚀$(WHITE)\n"

clean:
				@rm -rf $(OBJ)
				@make -C $(LIBFT) clean
				@make -C $(MLX) clean
				@rm -rf obj

fclean: 	clean
				@rm -rf $(NAME)
				@rm -rf bin

re: 		fclean all

.PHONY: 	all clean fclean re $(LIBFT) $(MLX) normi dependencies wsl2

#█████████████████████████████ Custom rules ████████████████████████████████████#

normi:
						@echo "$(YELLOW)Norminette...\n$(WHITE)"
						@norminette $(SRC)
						@echo "$(GREEN)\nNorminette Done!\n"

dependencies:
						sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
						@echo "$(GREEN)Dependencies installed!"

play:
						clear					
						@make re
						@./so_long assets/maps/finish_map.ber