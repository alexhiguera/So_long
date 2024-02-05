# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 19:29:01 by ahiguera          #+#    #+#              #
#    Updated: 2024/01/30 16:57:22 by ahiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror 
MLXFLAGS	= -framework OpenGL -framework AppKit

SRC 		= ./src/map.c
OBJ			= ${SRC:.c=.o}

MLX_DIR 	= ./includes/minilibx/
MLX			= $(MLX_DIR)/libmlx.a

LIBFT_DIR	= ./includes/Libft_2.0/
LIBFT		= $(LIBFT_DIR)/libft.a

all:		$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(SRC)
						@echo $(CURSIVE)$(YELLOW) "  Compiling $(NAME)..." $(NONE)
						@gcc $(CFLAGS) $(MLXFLAGS) $(LIBFT) $(MLX) $(SRC) -o $(NAME)
						@echo $(GREEN)"- Compiled -"$(NONE)

$(LIBFT):
						@make -s -C $(LIBFT_DIR) all clean -s

$(MLX):
						@make -C $(MLX_DIR) all -s
						@echo $(CURSIVE)$(GRAY) "  Making MLX" $(NONE)


clean:
						@make -C $(LIBFT_DIR) fclean
						@make -C $(MLX_DIR) clean
						@rm -f $(NAME)

fclean: 	clean
				

re: 		fclean all

.PHONY: 	all clean fclean re $(LIBFT) $(MLX)

#############################################################

#colors
NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'