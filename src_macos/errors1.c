//TODO: add header

#include "so_long.h"

static void	ft_is_rectangular(t_game *map)
{
	int	first_row;
	int	i;
	int	cmp_row;

	i = 0;
	first_row = ft_strlen(map->matrix[0]);
	while (i < map->height)
	{
		cmp_row = ft_strlen(map->matrix[i]);
		if (first_row != cmp_row)
		{
			so_print_error(5);
			so_exit(map);
		}
		i++;
	}
}

//checks if there is a valid char
//1 player = 1, 1 exit = 1, <= 1 collectable
static void	character_valid(t_game *map)
{
	int	height;
	int	width;

	map->collect_count = 0;
	map->player_count = 0;
	map->exit_count = 0;
	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			so_character_checker(map, width, height);
			so_count_checker(map, width, height);
			width++;
		}
		height++;
	}
	if (!map->player_count || !map->exit_count
		|| map->collect_count == 0)
	{
		so_print_error(4);
		so_exit(map);
	}
}

//checks if the map is surrounded by walls
//if not, prints error
static void	if_is_around_walls(t_game *map)
{
	int	horizontal_walls;
	int	vertical_walls;

	vertical_walls = so_vertical_walls(map);
	horizontal_walls = so_horizontal_walls(map);
	if (horizontal_walls == 0 || vertical_walls == 0)
	{
		so_print_error(2);
		so_exit(map);
	}
}

void	so_check_errors(t_game *map)
{
	ft_is_rectangular(map);
	if_is_around_walls(map);
	character_valid(map);
	so_flood_fill(map);
}
