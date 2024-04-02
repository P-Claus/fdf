/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:52:53 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/02 22:11:34 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix_cell	**allocate_matrix(int amount_of_rows, int amount_of_columns)
{
	t_matrix_cell	**array;
	int				row_iter;

	row_iter = 0;
	array = malloc(amount_of_rows * sizeof(t_matrix_cell *));
	if (!array)
		return (NULL);
	while (row_iter < amount_of_rows)
	{
		array[row_iter] = malloc(amount_of_columns * sizeof(t_matrix_cell));
		if (!array)
			return (NULL);
		row_iter++;
	}
	return (array);
}

void	calculate_matrix(char *name_of_file)
{
	char	*filename;
	char	*include_path;
	int		amount_of_rows;
	int		amount_of_columns;

	include_path = "./maps/";
	filename = ft_strjoin(include_path, name_of_file);
	amount_of_columns = calculate_amount_of_columns(filename, 0);
	amount_of_rows = calculate_amount_of_rows(filename);
	ft_printf("The amount of rows is: %d\n", amount_of_rows);
	ft_printf("The amount of columns is: %d\n", amount_of_columns);
	ft_printf("The size of the 2d array is: %d\n", amount_of_columns
		* amount_of_rows);
	fill_matrix(amount_of_rows, amount_of_columns, filename);
	free((void *)filename);
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

int	calculate_amount_of_columns_with_spaces(char *filename)
{
	int		fd;
	int		amount_of_columns;
	char	*temp;
	char	*result;

	amount_of_columns = 0;
	fd = open(filename, O_RDONLY);
	result = get_next_line(fd);
	temp = result;
	while (*result != '\0')
	{
		amount_of_columns++;
		result++;
	}
	free(temp);
	close(fd);
	return (amount_of_columns);
}
