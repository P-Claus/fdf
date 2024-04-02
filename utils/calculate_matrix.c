/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:52:53 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/02 13:30:10 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// returns a pointer to the matrix once it has been allocated on the heap?
void	fill_matrix(int amount_of_rows, int amount_of_columns, char *filename)
{
	int		**matrix;
	int		fd;
	char	*result;
	char	**split_result;
	int		iter;
	int		split_iter;

	split_iter = 0;
	iter = 0;
	matrix = allocate_matrix(amount_of_rows, amount_of_columns);
	(void)amount_of_columns;
	fd = open(filename, O_RDONLY);
	while (iter < amount_of_rows)
	{
		result = get_next_line(fd);
		if (result == NULL)
		{
			free(result);
			return ;
		}
		ft_printf("The result is: %s\n", result);
		split_result = ft_split(result, ' ');
		print_split(split_result);
		while (split_iter < amount_of_columns)
		{
			matrix[iter][split_iter] = ft_atoi(split_result[split_iter]);
			split_iter++;
		}
		free(result);
		free_split(split_result);
		split_iter = 0;
		iter++;
	}
	print_matrix(matrix, amount_of_rows, amount_of_columns);
	free_matrix(matrix, amount_of_rows);
	close(fd);
	/*
		amount_of_columns_with_spaces = calculate_amount_of_columns_with_spaces(filename)
			- 1;
		row_iter = -1;
		column_iter = 0;
		fd = open(filename, O_RDONLY);
		while (row_iter <= amount_of_rows)
		{
			result = get_next_line(fd);
			while (column_iter < amount_of_columns_with_spaces
				&& result != NULL)
			{
				if (result[column_iter] == 32)
				{
					column_iter++;
				}
				else
				{
					number_index = 0;
					while (result[column_iter] != ' '
						&& result[column_iter] != '\0')
					{
						number[number_index++] = result[column_iter++];
					}
					number[number_index] = '\0';
					matrix[row_iter][column_iter] = ft_atoi(number);
				}
				column_iter++;
			}
			column_iter = 0;
			row_iter++;
			free(result);
			(void)matrix;
		}
		close(fd);
		*/
}
int	**allocate_matrix(int amount_of_rows, int amount_of_columns)
{
	int	**array;
	int	row_iter;

	row_iter = 0;
	array = malloc(amount_of_rows * sizeof(int *));
	if (!array)
		return ((int **)1);
	while (row_iter < amount_of_rows)
	{
		array[row_iter] = malloc(amount_of_columns * sizeof(int));
		if (!array)
			return ((int **)1);
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
	amount_of_columns = calculate_amount_of_columns(filename);
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
	return (amount_of_columns - 1);
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