/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:21:40 by ahiguera          #+#    #+#             */
/*   Updated: 2023/10/19 16:01:46 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_chars(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = count_chars(n);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	if (n == 0)
		result[0] = '0';
	i = 0;
	while (n != 0)
	{
		if (n < 0)
			result[len - 1 - i] = -(n % 10) + '0';
		else
			result[len - 1 - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	result[len] = '\0';
	return (result);
}
