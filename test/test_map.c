/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:46:40 by ahiguera          #+#    #+#             */
/*   Updated: 2024/02/05 20:00:43 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	file_extension_verification(char *file, char *extension);

void	test_extension_verific(int testcase, char *file, char *extension)
{
	int		result;

	result = file_extension_verification(file, extension);
	printf("Test case %i: %s\n", testcase, result ? "OK!" : "Failed");
}

int	main(void)
{
	test_extension_verific(1, "document.txt", ".txt");
	test_extension_verific(2, "image.jpg", ".jpg");
	test_extension_verific(3, "document.csv", "");
	//debe fallar
	test_extension_verific(4, "", ".ber");
	return (0);
}
