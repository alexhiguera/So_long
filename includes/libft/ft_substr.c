/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:33:02 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/04 20:17:42 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	str_len;

	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	if (str_len <= start)
		len = 0;
	else if (str_len <= start + len)
		len = str_len - start;
	result = (char *)malloc((len + 1) * sizeof (char));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, str + start, len);
	result[len] = '\0';
	return (result);
}
