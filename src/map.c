/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:53 by ahiguera          #+#    #+#             */
/*   Updated: 2024/02/05 18:17:16 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	ft_print_map(char *file)
{
	size_t	i;
	int		fd;
	char	*map_save;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return ;
	}
	while (1)
	{
		map_save = get_next_line(fd);
		printf("resultado 1:\n%i \n", fd);
		i++;
	}
	close(fd);
	printf("resultado 2:\n%s \n", map_save);
}

int	file_extension_verification(char *file, char *extension)
{
	size_t	extension_len;
	size_t	file_len;
	size_t	i;

	extension_len = ft_strlen(extension);
	file_len = ft_strlen(file);
	i = 0;
	while (i < extension_len)
	{
		if (file[file_len - extension_len + i] != extension[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		printf("resultado: %i\n", file_extension_verification(argv[1], ".ber"));
	return (0);
}
