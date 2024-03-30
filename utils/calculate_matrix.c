/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:52:53 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/30 11:00:42 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// returns a pointer to the matrix once it has been allocated on the heap?
void	fill_matrix(int amount_of_rows, int amount_of_columns, char *filename)
{
	int		matrix[amount_of_rows][amount_of_columns];
	int		row_iter;
	int		column_iter;
	char	*result;
	int		fd;
	int		amount_of_columns_with_spaces;

	amount_of_columns_with_spaces = calculate_amount_of_columns_with_spaces(filename)
		- 1;
	row_iter = -1;
	column_iter = 0;
	fd = open(filename, O_RDONLY);
	while (row_iter <= amount_of_rows)
	{
		result = get_next_line(fd);
		while (column_iter < amount_of_columns_with_spaces)
		{
			if (result[column_iter] == 32)
			{
				column_iter++;
			}
			else
			{
				ft_printf("%c", result[column_iter]);
				matrix[row_iter][column_iter] = result[column_iter];
				column_iter++;
			}
		}
		column_iter = 0;
		row_iter++;
		ft_printf("\n");
		free(result);
	}
	(void)matrix;
	/*
	row_iter = 0;
	column_iter = 0;
	while (row_iter < amount_of_rows)
	{
		while (column_iter < amount_of_columns)
		{
			ft_printf("%c", matrix[row_iter][column_iter]);
			column_iter++;
		}
		column_iter = 0;
		ft_printf("\n");
		row_iter++;
	}
	*/
	close(fd);
}

void	calculate_matrix(char *name_of_file)
{
	char	*filename;
	char	*include_path;
	int		amount_of_rows;
	int		amount_of_columns;

	include_path = "./maps/";
	filename = ft_strjoin(include_path, name_of_file);
	amount_of_columns = calculate_amount_of_columns(filename);
	amount_of_rows = calculate_amount_of_rows(filename);
	ft_printf("The amount of rows is: %d\n", amount_of_rows);
	ft_printf("The amount of columns is: %d\n", amount_of_columns - 1);
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

int	calculate_amount_of_columns(char *filename)
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
		if (*result != 32)
			amount_of_columns++;
		result++;
	}
	free(temp);
	close(fd);
	return (amount_of_columns);
}
int	calculate_amount_of_columns_with_spaces(char *filename)
{
	int fd;
	int amount_of_columns;
	char *temp;
	char *result;

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