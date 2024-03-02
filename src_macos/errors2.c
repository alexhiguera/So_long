//TODO: add header

#include "so_long.h"

#define ERROR "\033[1;31m[Error]\033[0m\n"

void	so_print_error(int type)
{
	if (type == 1)
		ft_printf (ERROR "\033[35mMap extension is not .ber\033[0m\n");
	else if (type == 2)
		ft_printf (ERROR "\033[35mMap is not surrounded by walls\033[0m\n");
	else if (type == 3)
		ft_printf (ERROR "\033[35mInvalid char found\033[0m\n");
	else if (type == 4)
		ft_printf (ERROR "\033[35mEither P, E or C issue\033[0m\n");
	else if (type == 5)
		ft_printf (ERROR "\033[35mMap is not rectangular\033[0m\n");
	else if (type == 6)
		ft_printf (ERROR "\033[35mInvalid map\033[0m\n");
}

//horizontal walls check, checks the first and last line
int	so_horizontal_walls(t_game *map)
{
	int	i;
	int	j;

	i = map->width;
	j = 0;
	while (j < i)
	{
		if (map->matrix[0][j] == '0' || map->matrix[map->height - 1][j] == '0')
			return (0);
		j++;
	}
	return (1);
}

//vertical walls check, checks the first and last column
int	so_vertical_walls(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	j = map->width;
	while (map->height > i)
	{
		if (map->matrix[i][0] == '0' || map->matrix[i][j - 1] == '0')
			return (0);
		i++;
	}
	return (1);
}

void	so_character_checker(t_game *map, int width, int height)
{
	if (map->matrix[height][width] != 'P' && \
	map->matrix[height][width] != 'E' && \
	map->matrix[height][width] != 'C' && \
	map->matrix[height][width] != '1' && \
	map->matrix[height][width] != '0')
	{
		so_print_error(3);
		so_exit(map);
	}
}

//si el programa no ha terminado después de checkear si hay un carácter válido,
//vuelve a llamar a la matriz para contar los respectivos chars que queremos.
void	so_count_checker(t_game *map, int width, int height)
{
	if (map->matrix[height][width] == 'P')
		map->player_count++;
	if (map->matrix[height][width] == 'E')
		map->exit_count++;
	if (map->matrix[height][width] == 'C')
		map->collect_count++;
}
