/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/04/04 16:52:33 by alex             ###   ########.fr       */
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
		so_error("Map cant played");
	so_free(game);
}

void	so_error(char *message)
{
	ft_printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}
