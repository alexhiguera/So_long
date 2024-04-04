/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/04/04 17:36:21 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checks if the provided file has the correct extension.
Also stores the file path in the game structure. */

void	so_check_extension(char *argv1, t_game *game)
{
	int	i;

	i = ft_strlin(argv1);
	if (ft_strncmp(&argv1[i - 4], ".ber", 4) != 0)
	{
		so_error("Error\n Map file must have .ber extension \n");
	}
	game->map.path = argv1;
}

/* Checks that all read lines have the same length.
Also counts the number of lines (map height) and stores
the length in the game structure. */

void	so_check_map_dimension(t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = 0;
	fd = open(game->map.path, O_RDONLY | O_NOFOLLOW);
	if (fd < 0)
		so_error("Map not found");
	line = get_next_line(fd);
	if (!line)
		so_error("Map is empty");
	game->map.x = ft_strlin(line) - 1;
	while (line)
	{
		if (line[ft_strlin(line) - 1] == '\n')
			line[ft_strlin(line) - 1] = '\0';
		if (ft_strlin(line) != game->map.x)
			so_error("Map on x is irregular");
		game->map.y++;
		tmp = line;
		line = get_next_line(fd);
		free(tmp);
	}
	close(fd);
}

/* Finds the player's starting position on the map and updates the
coordinates with each move. */

void	so_get_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.y = y;
				game->player.x = x;
				game->map.map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

int	so_destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.collects);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.player);
	so_free(game);
	exit(EXIT_SUCCESS);
}
