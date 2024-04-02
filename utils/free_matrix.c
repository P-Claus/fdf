/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:55:21 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/02 17:55:29 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_matrix(t_matrix_cell **matrix, int amount_of_rows)
{
	int row_iter = 0;

	while (row_iter < amount_of_rows)
	{
		free(matrix[row_iter]);
		row_iter++;
	}
	free(matrix);
}