/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_amount_of_columns_in_matrix.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:47:45 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/05 11:07:51 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_amount_of_columns_in_matrix(t_matrix_cell **matrix)
{
	int column_iter = 0;

	while (matrix[0][column_iter].value)
	{
		column_iter++;
	}
	return (column_iter);
}