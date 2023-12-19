/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:53:18 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/11 12:47:42 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_putbase(unsigned long n, char *base, int *result)
{
	size_t	lenbase;

	lenbase = ft_strlen(base);
	if (n >= lenbase)
		pf_putbase((n / lenbase), base, result);
	pf_putchar(base[n % lenbase], result);
}

void	pf_putsigned(int n, int *result)
{
	if (n < 0)
	{
		pf_putchar('-', result);
		pf_putbase((unsigned int)(-n), DECIMAL, result);
	}
	else
		pf_putbase((unsigned int)n, DECIMAL, result);
}

void	pf_putpointer(void *ptr, int *result)
{
	pf_putstr(PTR_PREFIX, result);
	pf_putbase((unsigned long)ptr, HEXADECIMAL_LO, result);
}

void	pf_putuntilpercent(char *str, size_t *i, int *result)
{
	size_t	j;

	j = 0;
	while (str[*i + j] != '\0' && str[*i + j] != '%')
		j++;
	pf_betterwrite(&str[*i], j, result);
	*i += j;
}
