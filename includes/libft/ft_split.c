/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:46:24 by ahiguera          #+#    #+#             */
/*   Updated: 2023/12/04 20:08:32 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counter(char const *str, char c)
{
	size_t	i;
	size_t	total;

	i = 0;
	total = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			total++;
		i++;
	}
	return (total);
}

static char	*copy_word(char const *str, char c, size_t *i)
{
	char	*result;
	size_t	len;

	while (str[*i] != '\0' && str[*i] == c)
		(*i)++;
	len = 0;
	while (str[*i + len] != '\0' && str[*i + len] != c)
		len++;
	result = ft_substr(str, *i, len);
	*i += len;
	return (result);
}

static void	ft_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	size_t	num_words;
	size_t	i;
	size_t	j;

	if (str == NULL)
		return (NULL);
	num_words = counter(str, c);
	result = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < num_words)
	{
		result[j] = copy_word(str, c, &i);
		if (result[j] == NULL)
		{
			ft_free(result);
			return (NULL);
		}
		j++;
	}
	result[num_words] = NULL;
	return (result);
}
