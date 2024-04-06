/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/04/06 02:10:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_free(t_game *game)
{
	int	y;

	y = -1;
	while (game->map.map[++y])
		free(game->map.map[y]);
	free(game->map.map);
	game->map.map = NULL;
}

void	so_handler_errors(t_game *game)
{
	if (game->player.c_collects != game->player.tokens
		|| game->player.exit == false)
		so_error("Map cant played\n");
	so_free(game);
}

void	so_error(char *message)
{
	ft_printf("\033[31mError: %s\n", message);
	exit(EXIT_FAILURE);
}
