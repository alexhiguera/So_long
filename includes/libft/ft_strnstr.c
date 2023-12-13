/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:31:51 by ahiguera          #+#    #+#             */
/*   Updated: 2023/10/18 16:18:16 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	i;

	n_len = ft_strlen(n);
	if (n_len == 0)
		return ((char *)h);
	h_len = ft_strlen(h);
	if (len < h_len)
		h_len = len;
	if (h_len < n_len)
		return (NULL);
	i = 0;
	while (i <= h_len - n_len)
	{
		if (ft_memcmp(h + i, n, n_len) == 0)
			return ((char *)h + i);
		i++;
	}
	return (NULL);
}
