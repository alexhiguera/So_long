/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:59:05 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/04 20:05:38 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t src, size_t size)
{
	void	*result;

	result = malloc(src * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, src * size);
	return (result);
}
