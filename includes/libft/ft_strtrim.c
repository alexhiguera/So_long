/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:50:45 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/04 20:16:54 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*result;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (str[start] && is_in_set(str[start], set))
		start++;
	end = ft_strlen(str);
	while (end > start && is_in_set(str[end - 1], set))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		result[i++] = str[start++];
	result[i] = '\0';
	return (result);
}
