/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:16:32 by ahiguera          #+#    #+#             */
/*   Updated: 2024/01/30 16:34:31 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/Libft_2.0/src/libft.h"
# include "../includes/minilibx/mlx.h"

# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
}				t_map;

#endif