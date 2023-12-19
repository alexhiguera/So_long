/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:53:36 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/12 17:28:07 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pf_putformat(char *str, size_t *i, int *result, va_list src)
{
	if (str[*i + 1] == 'c')
		pf_putchar((char)va_arg(src, int), result);
	else if (str[*i + 1] == 's')
		pf_putstr(va_arg(src, char *), result);
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		pf_putsigned(va_arg(src, int), result);
	else if (str[*i + 1] == 'u')
		pf_putbase(va_arg(src, unsigned int), DECIMAL, result);
	else if (str[*i + 1] == 'x')
		pf_putbase(va_arg(src, unsigned int), HEXADECIMAL_LO, result);
	else if (str[*i + 1] == 'X')
		pf_putbase(va_arg(src, unsigned int), HEXADECIMAL_UP, result);
	else if (str[*i + 1] == 'o')
		pf_putbase(va_arg(src, unsigned int), OCTAL, result);
	else if (str[*i + 1] == 'p')
		pf_putpointer(va_arg(src, void *), result);
	else if (str[*i + 1] == '%')
		pf_putchar('%', result);
	*i += 1;
	if (str[*i] != '\0')
		*i += 1;
}

int	ft_printf(char const *h, ...)
{
	size_t	i;
	va_list	src;
	int		result;

	i = 0;
	result = 0;
	va_start(src, h);
	while (result != -1 && h[i] != '\0')
	{
		if (h[i] == '%')
			pf_putformat((char *)h, &i, &result, src);
		else
			pf_putuntilpercent((char *)h, &i, &result);
	}
	va_end(src);
	return (result);
}
