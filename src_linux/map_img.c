//TODO: add header

#include "so_long.h"

void	so_put_images(t_game *map)
{
	int	i;
	int	j;

	map->floor = mlx_xpm_file_to_image(map->win_ptr, \
					"images/floor.xpm", &i, &j);
	map->wall = mlx_xpm_file_to_image(map->win_ptr, \
					"images/wall.xpm", &i, &j);
	map->exit = mlx_xpm_file_to_image(map->win_ptr, \
					"images/exit.xpm", &i, &j);
	map->collectables = mlx_xpm_file_to_image(map->win_ptr, \
					"images/item.xpm", &i, &j);
	map->player = mlx_xpm_file_to_image(map->win_ptr, \
					"images/player.xpm", &i, &j);
	if (map->floor == NULL || map->wall == NULL || \
			map->exit == NULL || map->collectables == NULL \
			|| map->player == NULL)
		ft_printf("Error al cargar la imagen");
	else
		ft_printf("Se ha cargado la imagen correctamente\n");
}

static void	ft_add_images_aux(t_game *map, int height, int width)
{
	if (map->matrix[height][width] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->wall, (width * WINDOW_WIDTH), (height * WINDOW_HEIGHT));
	if (map->matrix[height][width] == '0'
		|| map->matrix[height][width] == 'E'
		|| map->matrix[height][width] == 'P'
		|| map->matrix[height][width] == 'I')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->floor, (width * WINDOW_WIDTH), (height * WINDOW_HEIGHT));
	if (map->matrix[height][width] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->collectables, (width * WINDOW_WIDTH), \
		(height * WINDOW_HEIGHT));
	if (map->matrix[height][width] == 'E' || map->matrix[height][width] == 'I')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->exit, (width * WINDOW_WIDTH), (height * WINDOW_HEIGHT));
	if (map->matrix[height][width] == 'P' || map->matrix[height][width] == 'I')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player,
			(width * WINDOW_WIDTH), (height * WINDOW_HEIGHT));
}

/* place walls, floor, player, collectable and ext images into mlx_window */
int	so_add_to_win(t_game *map)
{
	int	height;
	int	width;

	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			ft_add_images_aux(map, height, width);
			width++;
		}
		height++;
	}
	return (1);
}
