/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:23:11 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/02 13:29:23 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_matrix(int **matrix, int amount_of_rows, int amount_of_columns)
{
	int column_iter = 0;
	int row_iter = 0;

	while (row_iter < amount_of_rows)
	{
		while (column_iter < amount_of_columns)
		{
			ft_printf("%d", matrix[row_iter][column_iter]);
			column_iter++;
		}
		ft_printf("\n");
		column_iter = 0;
		row_iter++;
	}
}