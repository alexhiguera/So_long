/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/03/30 23:55:23 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_0(t_game *game, int my, int mx)
{
	if (game->map.map[game->player.y][game->player.x] != 'D')
		game->map.map[game->player.y][game->player.x] = '0';
	else
		game->map.map[game->player.y][game->player.x] = 'E';
	game->map.map[game->player.y + my][game->player.x + mx] = 'P';
	game->player.y += my;
	game->player.x += mx;
	so_print_sprites(game);
	ft_printf("moves -> %d\n", game->player.moves++);
}

static void	check_collects(t_game *game, int my, int mx)
{
	game->player.tokens--;
	if (game->map.map[game->player.y][game->player.x] != 'D')
		game->map.map[game->player.y][game->player.x] = '0';
	else
		game->map.map[game->player.y][game->player.x] = 'E';
	game->map.map[game->player.y + my][game->player.x + mx] = 'P';
	game->player.y += my;
	game->player.x += mx;
	so_print_sprites(game);
	ft_printf("moves -> %d\n", game->player.moves++);
}

static void	moves(t_game *game, int my, int mx)
{
	int	py;
	int	px;

	py = game->player.y;
	px = game->player.x;
	if (game->map.map[py + my][px + mx] == '1')
		return ;
	if (game->map.map[py + my][px + mx] == '0')
		return (check_0(game, my, mx));
	if (game->map.map[py + my][px + mx] == 'E' && game->player.tokens == 0)
		return ((void)(so_destroy_window(game)));
	if (game->map.map[py + my][px + mx] == 'C')
		return (check_collects(game, my, mx));
	else
		game->map.map[py][px] = '0';
	if (game->map.map[py + my][px + mx] == 'E')
	{
		game->map.map[game->player.y + my][game->player.x + mx] = 'D';
		game->player.y += my;
		game->player.x += mx;
	}
	so_print_sprites(game);
	ft_printf("moves -> %d\n", game->player.moves++);
}

int	so_handler_keys(int keycode, t_game *game)
{
	if (keycode == Q || keycode == ESC)
		so_destroy_window(game);
	else if (keycode == W || keycode == KEY_UP)
		moves(game, -1, 0);
	else if (keycode == S || keycode == KEY_DOWN)
		moves(game, 1, 0);
	else if (keycode == A || keycode == KEY_LEFT)
		moves(game, 0, -1);
	else if (keycode == D || keycode == KEY_RIGHT)
		moves(game, 0, 1);
	return (0);
}
