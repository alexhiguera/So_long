//TODO: add header

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/mlx_linux/mlx.h"
# include "../includes/Libft_2.0/src/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WINDOW_WIDTH	64
# define WINDOW_HEIGHT	64

//hooks
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_game
{
	char		**matrix;
	int			collect_count;
	int			player_count;
	int			exit_count;
	int			x;
	int			y;
	int			height;
	int			width;
	int			step;

	void		*floor;
	void		*wall;
	void		*collectables;
	void		*exit;
	void		*player;

	t_pos		player_pos;

	void		*mlx_ptr;
	void		*win_ptr;
}				t_game;

#endif

