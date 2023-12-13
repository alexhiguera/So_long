/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:55:56 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/11 12:47:49 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_betterwrite(void *buf, size_t len, int *result)
{
	ssize_t	w;

	if (*result == -1)
		return ;
	w = write(STDOUT_FILENO, buf, len);
	if (w == -1)
		*result = -1;
	else
		*result += w;
}

void	pf_putchar(char c, int *result)
{
	pf_betterwrite(&c, 1, result);
}

void	pf_putstr(char *str, int *result)
{
	if (str == NULL)
		return (pf_putstr(NULL_STR, result));
	pf_betterwrite(str, ft_strlen(str), result);
}
