/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:27:01 by ahiguera          #+#    #+#             */
/*   Updated: 2023/10/18 15:21:08 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*origin;
	char	*dest;

	if (dst == NULL && src == NULL && n != 0)
		return (NULL);
	i = 0;
	origin = (char *)src;
	dest = (char *)dst;
	while (i < n)
	{
		dest[i] = origin[i];
		i++;
	}
	return (dst);
}
