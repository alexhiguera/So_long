/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/04/04 17:05:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_other_things(t_game *game, int y, int x)
{
	if (game->map.map[y][x] != '1' && game->map.map[y][x] != '0'
		&& game->map.map[y][x] != '\n')
		so_error("Char on map Invalid");
}

void	so_count_things(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
				game->map.player++;
			else if (game->map.map[y][x] == 'C')
				game->player.c_collects++;
			else if (game->map.map[y][x] == 'E')
				game->map.count++;
			else
				check_other_things(game, y, x);
			x++;
		}
		y++;
	}
	if (game->map.player != 1 || game->map.count != 1
		|| game->player.c_collects < 1 || game->map.count != 1)
		so_error("Invalid map");
}

void	so_read_map(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = 0;
	fd = open(game->map.path, O_RDONLY);
	if (fd < 0)
		so_error("Map not found");
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.y + 1));
	if (!game->map.map)
		return ;
	line = get_next_line(fd);
	if (!line)
		so_error("Map is empty");
	i = 0;
	while (i < game->map.y)
	{
		game->map.map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	game->map.map[i] = NULL;
	close(fd);
}

void	so_check_perimeter(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x;
	y = game->map.y;
	while (x--)
	{
		if (game->map.map[0][x] != '1' || game->map.map[y - 1][x] != '1')
			so_error("Map is not closed");
	}
	while (y--)
	{
		if (game->map.map[y][0] != '1' || game->map.map[y][game->map.x
			- 1] != '1')
			so_error("Map is not closed");
	}
}
