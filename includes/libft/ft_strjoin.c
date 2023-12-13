/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:52:54 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/04 20:11:09 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, str1, len1);
	ft_memcpy(result + len1, str2, len2);
	result[len1 + len2] = '\0';
	return (result);
}
