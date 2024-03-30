/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/03/30 23:55:23 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_number_of_args(int argc)
{
	if (argc != 2)
	{
		so_error("Error\nInvalid number of arguments\n");
	}
}

void	hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1, so_destroy_window, game);
	mlx_hook(game->mlx_win, 2, 1, so_handler_keys, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_number_of_args(argc);
	ft_bzero(&game, sizeof(t_game));
	so_check_extension(argv[1], &game);
	so_get_len(&game);
	so_read_map(&game);
	so_check_perimeter(&game);
	so_count_things(&game);
	so_get_player(&game);
	so_flood_fill(&game);
	so_handler_errors(&game);
	so_read_map(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map.x * 64, game.map.y * 64,
			"so_long");
	hooks(&game);
	so_print_sprites(&game);
	mlx_loop(game.mlx);
	return (0);
}
