/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:23:11 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/02 17:41:24 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_matrix(t_matrix_cell **matrix, int amount_of_rows,
		int amount_of_columns)
{
	int column_iter = 0;
	int row_iter = 0;

	while (row_iter < amount_of_rows)
	{
		while (column_iter < amount_of_columns)
		{
			ft_printf("%d", matrix[row_iter][column_iter].value);
			if (matrix[row_iter][column_iter].color != -1)
				ft_printf(",%d ", matrix[row_iter][column_iter].color);
			column_iter++;
		}
		ft_printf("\n");
		column_iter = 0;
		row_iter++;
	}
	return ;
}