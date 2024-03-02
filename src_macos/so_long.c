/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: columbux <columbux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/03/02 18:55:08 by columbux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: change header

#include "so_long.h"

/* En el bucle va liberando la memoria asignada a cada fila */
int	so_exit(t_game *map)
{
	int	line;

	line = 0;
	if (map->win_ptr)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	while (line < map->height - 1)
		free (map->matrix[line++]);
	free(map->matrix);
	exit(0);
}

void	so_print_map(char **map)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	map;
	int		len;

	if (argc != 2)
		return (0);
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0)
	{
		so_print_error(1);
		return (0);
	}
	so_reading_the_map(&map, argv);
	so_check_errors(&map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, (map.width * WINDOW_WIDTH),
			(map.height * WINDOW_HEIGHT), "solong");
	so_put_images(&map);
	so_add_to_win(&map);
	map.step = 0;
	mlx_loop_hook(map.mlx_ptr, &so_add_to_win, &map);
	mlx_hook(map.win_ptr, 2, 1, &so_hook, &map);
	mlx_hook(map.win_ptr, 17, 1, (void *)exit, &map);
	mlx_loop(map.mlx_ptr);
}
