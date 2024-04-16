/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:41:29 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/04 16:41:52 by pclaus           ###   ########.fr       */
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