/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/04/06 02:01:33 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	charge_sprites(t_game *game)
{
	int	x;
	int	y;

	game->img.collects = mlx_xpm_file_to_image(game->mlx, COIN, &(x), &(y));
	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &(x), &(y));
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &(x), &(y));
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &(x), &(y));
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &(x), &(y));
	if (game->img.collects == 0 || game->img.player == 0 || game->img.floor == 0
		|| game->img.exit == 0 || game->img.wall == 0)
		so_error("Could not load sprites\n");
}

static void	sprites_in_map(t_game *game, int x, int y)
{
	char	current;

	current = game->map.map[y][x];
	if (current == '1')
	{
		put_wall(game, x, y);
		return ;
	}
	put_floor(game, x, y);
	if (current == 'C')
		put_collects(game, x, y);
	if (current == 'E')
		put_exit(game, x, y);
	if (current == 'P')
		put_player(game, x, y);
	if (current == 'D')
		put_player_exit(game, x, y);
}

void	so_print_sprites(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	charge_sprites(game);
	while (game->map.map[y] != 0)
	{
		x = 0;
		while (game->map.map[y][x] != 0)
		{
			sprites_in_map(game, x, y);
			x++;
		}
		y++;
	}
}
