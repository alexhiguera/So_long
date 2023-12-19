/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/19 17:47:14 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

/**
 * Prints the map to the standard output.
 *
 * @param map The map structure containing the map data.
 */
void	ft_print_map(t_map *map)
{
	int row_len;
	int cols_len;

	row_len = 0;
	while (row_len < map->rows)
	{
		cols_len = 0;
		while (cols_len < map->cols)
		{
			ft_putchar_fd(map->map[row_len][cols_len], 1);
			cols_len++;
		}
		ft_putchar_fd('\n', 1);
		row_len++;
	}
}