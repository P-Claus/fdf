/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:17:53 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/04 18:20:07 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix_cell	**make_matrix(char *name_of_file)
{
	char	*filename;
	char	*include_path;
	int		amount_of_rows;
	int		amount_of_columns;
	t_matrix_cell **matrix = NULL;

	include_path = "./maps/";
	filename = ft_strjoin(include_path, name_of_file);
	amount_of_columns = calculate_amount_of_columns(filename, 0);
	amount_of_rows = calculate_amount_of_rows(filename);
	ft_printf("The amount of rows is: %d\n", amount_of_rows);
	ft_printf("The amount of columns is: %d\n", amount_of_columns);
	ft_printf("The size of the 2d array is: %d\n", amount_of_columns
		* amount_of_rows);
	matrix = fill_matrix(amount_of_rows, amount_of_columns, filename);
	free((void *)filename);
	return (matrix);
}

int	calculate_amount_of_rows(char *filename)
{
	int		fd;
	int		amount_of_rows;
	char	*result;

	amount_of_rows = 0;
	fd = open(filename, O_RDONLY);
	result = get_next_line(fd);
	while (result != 0)
	{
		free(result);
		result = get_next_line(fd);
		amount_of_rows++;
	}
	free(result);
	close(fd);
	return (amount_of_rows);
}

int	calculate_amount_of_columns(char *filename, int iter)
{
	int		fd;
	int		amount_of_columns;
	char	**split;
	char	*result;

	amount_of_columns = 0;
	fd = open(filename, O_RDONLY);
	result = get_next_line(fd);
	split = ft_split(result, ' ');
	while (split[iter])
	{
		amount_of_columns++;
		iter++;
	}
	iter = 0;
	while (split[iter])
	{
		free(split[iter]);
		iter++;
	}
	free(split);
	free(result);
	close(fd);
	return (amount_of_columns);
}
