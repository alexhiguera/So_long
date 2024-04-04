/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:16:32 by ahiguera          #+#    #+#             */
/*   Updated: 2024/04/04 17:33:12 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/Libft_2.0/src/libft.h"
# include "../includes/mlx_macos/mlx.h"
# include <fcntl.h>

# define WALL "assets/sprites/wall.xpm"
# define FLOOR "assets/sprites/flor.xpm"
# define PLAYER "assets/sprites/player.xpm"
# define EXIT "assets/sprites/exit.xpm"
# define COIN "assets/sprites/coins.xpm"

# define Q 12
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 0x35
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct s_map
{
	char		**map;
	int			x;
	int			y;
	char		*path;
	int			player;
	int			count;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			tokens;
	int			c_collects;
	int			moves;
	bool		exit;
}				t_player;

typedef struct s_image
{
	void		*collects;
	void		*player;
	void		*wall;
	void		*floor;
	void		*exit;
}				t_image;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_image		img;
	t_player	player;
}				t_game;

// errors.c
void			so_free(t_game *game);
void			so_handler_errors(t_game *game);
void			so_error(char *message);

// flood_fill.c
void			so_flood_fill(t_game *game);

// getmap.c
void			so_check_extension(char *argv1, t_game *game);
void			so_check_map_dimension(t_game *game);
int				so_destroy_window(t_game *game);
void			so_get_player(t_game *game);

// keys.c
int				so_handler_keys(int keycode, t_game *game);

//put_things.c
void			put_player(t_game *game, int x, int y);
void			put_exit(t_game *game, int x, int y);
void			put_collects(t_game *game, int x, int y);
void			put_wall(t_game *game, int x, int y);
void			put_floor(t_game *game, int x, int y);

//read_map.c
void			so_read_map(t_game *game);
void			so_check_perimeter(t_game *game);
void			so_count_things(t_game *game);

// sprites.c
void			so_print_sprites(t_game *game);


#endif