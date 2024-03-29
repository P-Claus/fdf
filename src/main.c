/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:05:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/29 17:07:28 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <string.h>

int	main(int argc, char **argv)
{
	char	*filename;
	char	*include_path;
	int		fd_first_line;
	char	*result;
	char	*temp;
	int		amount_of_columns;
	int		fd_result;
	int		amount_of_rows;

	amount_of_rows = 0;
	amount_of_columns = 0;
	if (argc == 2)
	{
		include_path = "./maps/";
		filename = ft_strjoin(include_path, argv[1]);
		fd_first_line = open(filename, O_RDONLY);
		result = get_next_line(fd_first_line);
		temp = result;
		while (*result != '\0')
		{
			if (*result != 32)
				amount_of_columns++;
			result++;
		}
		free(temp);
		close(fd_first_line);
		fd_result = open(filename, O_RDONLY);
		result = get_next_line(fd_result);
		while (!result == 0)
		{
			free(result);
			result = get_next_line(fd_result);
			amount_of_rows++;
		}
		ft_printf("The amount of rows is: %d\n", amount_of_rows);
		ft_printf("The amount of columns is: %d\n", amount_of_columns - 1);
		ft_printf("The result is: %s", result);
		free(result);
		close(fd_result);
		free((void *)filename);
	}
}
