/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:20:41 by ahiguera          #+#    #+#             */
/*   Updated: 2023/10/16 15:55:35 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_reversecopy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*origin;
	char	*dest;

	origin = (char *)src;
	dest = (char *)dst;
	i = n - 1;
	while (i + 1 > 0)
	{
		dest[i] = origin[i];
		i--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	ssize_t	no;

	no = (ssize_t)n;
	if (dst - src > 0 && dst - src < no)
		return (ft_reversecopy(dst, src, n));
	else
		return (ft_memcpy(dst, src, n));
}
