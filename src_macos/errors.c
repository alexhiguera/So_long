/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/03/30 22:10:35 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_game *game)
{
	int	y;

	y = -1;
	while (game->map.map[++y])
		free(game->map.map[y]);
	free(game->map.map);
	game->map.map = NULL;
}

void	handler_errors(t_game *game)
{
	if (game->player.c_collects != game->player.tokens
		|| game->player.exit == false)
		ft_error("Map cant played");
	ft_free(game);
}
