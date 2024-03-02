//TODO: add header

#include "so_long.h"

void	fill(char **matrix, t_pos size, t_pos cur, char to_fill)
{
	if (((cur.y < 0 || cur.y > size.y) || (cur.x < 0 || cur.x > size.x))
		|| matrix[cur.y][cur.x] == '1' || matrix[cur.y][cur.x] == to_fill)
		return ;
	matrix[cur.y][cur.x] = 'P';
	fill(matrix, size, (t_pos){cur.x - 1, cur.y}, to_fill);
	fill(matrix, size, (t_pos){cur.x + 1, cur.y}, to_fill);
	fill(matrix, size, (t_pos){cur.x, cur.y - 1}, to_fill);
	fill(matrix, size, (t_pos){cur.x, cur.y + 1}, to_fill);
}

/* Save the position of the character you want 
 */
static t_pos	find_char(char **map, char character)
{
	t_pos	position;
	int		x;
	int		y;

	position.x = -1;
	position.y = -1;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == character)
			{
				position.x = x;
				position.y = y;
				return (position);
			}
			x++;
		}
		y++;
	}
	return (position);
}

void	so_flood_fill(t_game *map)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(*map) * (map->height + 1));
	while (i < map->height)
	{
		tmp[i] = ft_strdup(map->matrix[i]);
		i++;
	}
	tmp[i] = NULL;
	map->player_pos = find_char(map->matrix, 'P');
	tmp[map->player_pos.y][map->player_pos.x] = '0';
	fill(tmp, (t_pos){map->width - 1, map->height - 1}, map->player_pos, 'P');
	if (find_char(tmp, 'C').x != -1 || find_char(tmp, 'E').x != -1)
	{
		so_print_error(6);
		so_exit(map);
	}
}
