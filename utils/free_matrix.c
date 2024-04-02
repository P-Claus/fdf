/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:55:21 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/02 09:02:07 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_matrix(int **matrix, int amount_of_rows)
{
	int row_iter = 0;

	while (row_iter < amount_of_rows)
	{
		free(matrix[row_iter]);
		row_iter++;
	}
	free(matrix);
}