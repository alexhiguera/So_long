//TODO: add header

#include "so_long.h"

static void	movements_aux(t_game *map, int x, int y)
{
	if (y < 0 || y >= map->height || map->matrix[y][x] == '1')
		return ;
	map->step++;
	if (map->matrix[y][x] == 'E' && map->collect_count == 0)
	{
		ft_printf("\033[32mCONGRATS YOU HAVE WON!\033[0m\n");
		so_exit(map);
	}
	if (map->matrix[y][x] == 'C')
		map->collect_count -= 1;
	if (map->matrix[map->player_pos.y][map->player_pos.x] == 'I')
		map->matrix[map->player_pos.y][map->player_pos.x] = 'E';
	else
		map->matrix[map->player_pos.y][map->player_pos.x] = '0';
	map->player_pos.y = y;
	map->player_pos.x = x;
	if (map->matrix[y][map->player_pos.x] == 'E')
		map->matrix[map->player_pos.y][map->player_pos.x] = 'I';
	else
		map->matrix[map->player_pos.y][map->player_pos.x] = 'P';
	ft_printf("Steps: %d\n", map->step);
}

/* Moves the player up and down, right and left*/
static void	movements(t_game *map, int movement)
{
	int	x;
	int	y;

	x = map->player_pos.x;
	y = map->player_pos.y;
	if (movement == KEY_W || movement == KEY_UP)
		y -= 1;
	else if (movement == KEY_S || movement == KEY_DOWN)
		y += 1;
	else if (movement == KEY_A || movement == KEY_LEFT)
		x -= 1;
	else if (movement == KEY_D || movement == KEY_RIGHT)
		x += 1;
	movements_aux(map, x, y);
}

/* works return 1 if the keys has been press */
int	so_hook(int key, t_game *map)
{
	if (key == KEY_ESC)
		so_exit(map);
	if (key == KEY_W || key == KEY_UP || key == KEY_S || key == KEY_DOWN
		|| key == KEY_D || key == KEY_RIGHT || key == KEY_A || key == KEY_LEFT)
		movements(map, key);
	return (1);
}
