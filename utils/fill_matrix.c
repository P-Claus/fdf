/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:36:35 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/10 15:09:00 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix_cell	**fill_matrix(int amount_of_rows, int amount_of_columns,
		char *filename)
{
	t_matrix_cell	**matrix;
	int				fd;
	char			*result;
	int				iter;

	iter = 0;
	matrix = allocate_matrix(amount_of_rows, amount_of_columns);
	fd = open(filename, O_RDONLY);
	while (iter < amount_of_rows)
	{
		result = get_next_line(fd);
		if (result == NULL)
		{
			free(result);
			return (matrix);
		}
		put_data_into_matrix(matrix, result, iter, amount_of_columns);
		free(result);
		iter++;
	}
	print_matrix(matrix, amount_of_rows, amount_of_columns);
	close(fd);
	return (matrix);
}

void	put_data_into_matrix(t_matrix_cell **matrix, char *result, int iter,
		int amount_of_columns)
{
	char	**split_result;
	int		split_iter;

	split_iter = 0;
	split_result = ft_split(result, ' ');
	while (split_iter < amount_of_columns)
	{
		if (ft_strchr(split_result[split_iter], ','))
			split_for_color(matrix, split_result, split_iter, iter);
		else
			matrix[iter][split_iter].color = 16711935;
		matrix[iter][split_iter].value = ft_atoi(split_result[split_iter]);
		split_iter++;
	}
	free_split(split_result);
}

void	split_for_color(t_matrix_cell **matrix, char **split_result,
		int split_iter, int iter)
{
	char	**split_color;

	split_color = ft_split(split_result[split_iter], ',');
	matrix[iter][split_iter].color = ft_hex_string_to_int(split_color[1]);
	ft_printf("Color is: %d\n", matrix[iter][split_iter].color);
	free(split_color[0]);
	free(split_color[1]);
	free(split_color);
}
