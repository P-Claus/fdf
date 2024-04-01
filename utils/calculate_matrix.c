/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:52:53 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/01 10:19:33 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// returns a pointer to the matrix once it has been allocated on the heap?
void	fill_matrix(int amount_of_rows, int amount_of_columns, char *filename)
{
	int		**matrix;
	int		fd;
	char	*result;
	char	**split1;
	int		split_iter;
	char	**split2;
	char	**split3;

	matrix = allocate_matrix(amount_of_rows, amount_of_columns);
	(void)amount_of_rows;
	(void)amount_of_columns;
	(void)matrix;
	split_iter = 0;
	// int		column_iter;
	// int		amount_of_columns_with_spaces;
	// int		number_index;
	// char	number[32];
	fd = open(filename, O_RDONLY);
	result = get_next_line(fd);
	ft_printf("The result is: %s\n", result);
	split1 = ft_split(result, ' ');
	while (split1[split_iter])
	{
		ft_printf("The string is: %s\n", split1[split_iter]);
		split_iter++;
	}
	free(result);
	split_iter = 0;
	while (split1[split_iter])
	{
		free(split1[split_iter]);
		split_iter++;
	}
	free(split1);
	split_iter = 0;
	/////////
	result = get_next_line(fd);
	ft_printf("The result is: %s\n", result);
	split2 = ft_split(result, ' ');
	ft_printf("split2 is: %p\n", (void *)split2);
	// while (split2[split_iter])
	//{
	// ft_printf("The string is: %s\n", split2[split_iter]);
	// split_iter++;
	//}
	free(result);
	split_iter = 0;
	while (split2[split_iter])
	{
		free(split2[split_iter]);
		split_iter++;
	}
	free(split2);
	split_iter = 0;
	/////////
	result = get_next_line(fd);
	ft_printf("The result is: %s\n", result);
	split3 = ft_split(result, ' ');
	while (split3[split_iter])
	{
		ft_printf("The string is: %s\n", split3[split_iter]);
		split_iter++;
	}
	free(result);
	split_iter = 0;
	while (split3[split_iter])
	{
		free(split3[split_iter]);
		split_iter++;
	}
	free(split3);
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
	// free the array and pointers
	// row_iter = 0;
	// while (row_iter < amount_of_rows)
	//{
	// free(array[row_iter]);
	// row_iter++;
	//}
	// free(array);
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