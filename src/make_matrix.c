/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:17:53 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/16 19:44:15 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix_cell	**make_matrix(char *name_of_file)
{
	int				amount_of_rows;
	int				amount_of_columns;
	char			*filename;
	t_matrix_cell	**matrix;

	matrix = NULL;
	filename = get_filename(name_of_file);
	amount_of_columns = calculate_amount_of_columns(filename, 0);
	amount_of_rows = calculate_amount_of_rows(filename);
	matrix = fill_matrix(amount_of_rows, amount_of_columns, filename);
	free((void *)filename);
	return (matrix);
}
