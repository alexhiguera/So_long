/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/03/30 22:10:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handler_recursivity(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'F')
		return ;
	if (game->map.map[y][x] == 'C')
		game->player.tokens++;
	if (game->map.map[y][x] == 'E')
		game->player.exit = true;
	game->map.map[y][x] = 'F';
	handler_recursivity(game, y + 1, x);
	handler_recursivity(game, y - 1, x);
	handler_recursivity(game, y, x + 1);
	handler_recursivity(game, y, x - 1);
}

void	handler_ff(t_game *game)
{
	handler_recursivity(game, game->player.y, game->player.x);
}
