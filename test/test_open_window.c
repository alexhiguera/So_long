/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:00:16 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/18 17:03:33 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "So_long)");
	mlx_loop(mlx);
}
