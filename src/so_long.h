/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:16:32 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/19 17:11:04 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "./includes/libft/libft.h"
# include "../includes/minilibx/mlx.h"

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
}				t_map;

#endif