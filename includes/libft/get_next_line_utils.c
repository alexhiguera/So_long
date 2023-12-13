/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:48:11 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/11 15:30:56 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gn_strncpy(char *result, char *orin, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && orin[i] != '\0')
	{
		result[i] = orin[i];
		i++;
	}
	result[len] = '\0';
}

void	gn_free(char *fres)
{
	if (fres != NULL)
		free (fres);
}

char	gn_strchr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
