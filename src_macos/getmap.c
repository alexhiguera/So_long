/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/04/04 16:35:01 by alex             ###   ########.fr       */
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
		so_error("Error\nMap not found\n");
	line = get_next_line(fd);
	if (!line)
		so_error("Error\nMap is empty\n");
	game->map.x = ft_strlin(line) - 1;
	while (line)
	{
		if (line[ft_strlin(line) - 1] == '\n')
			line[ft_strlin(line) - 1] = '\0';
		if (ft_strlin(line) != game->map.x)
			so_error("Error\nMap on x is irregular\n");
		game->map.y++;
		tmp = line;
		line = get_next_line(fd);
		free(tmp);
	}
	close(fd);
}
