/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:05:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/26 18:13:29 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <string.h>

int	main(int argc, char **argv)
{
	// int fd;
	const char *filename;
	const char *include_path;
	int fd;
	char *result;
	char *first_line;
	int amount_of_rows = 0;
	int amount_of_columns = 0;
	// char **split_array;
	// int iter = 0;

	if (argc == 2)
	{
		include_path = "./maps/";
		filename = ft_strjoin(include_path, (const char *)argv[1]);
		fd = open(filename, O_RDONLY);
		result = get_next_line(fd);
		first_line = result;
		while (!result == 0)
		{
			result = get_next_line(fd);
			amount_of_rows++;
		}
		ft_printf("The amount of rows is: %d\n", amount_of_rows);
		result = get_next_line(fd);
		while (*first_line != '\0')
		{
			if (*first_line != 32)
				amount_of_columns++;
			first_line++;
		}
		ft_printf("The amount of columns is: %d\n", amount_of_columns - 1);
		// ft_printf("The result is: %s", result);
		// split_array = ft_split(result, 32);
		// while (split_array[iter])
		//{
		// ft_printf("%s", split_array[iter]);
		// free(split_array[iter]);
		// iter++;
		//}
		// free(split_array);
		free(result);
		close(fd);
		free((void *)filename);
	}
}