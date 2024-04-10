/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_map_limits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:55:11 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/10 15:38:48 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calculate_map_limits(int ***iso_matrix, t_map_dimensions map_dimensions,
		t_map_limits *map_limits)
{
	int	i;
	int	j;

	map_limits->min_x_value = iso_matrix[0][0][0];
	map_limits->max_x_value = iso_matrix[0][0][0];
	map_limits->min_y_value = iso_matrix[1][0][0];
	map_limits->max_y_value = iso_matrix[1][0][0];
	i = 0;
	while (i < map_dimensions.rows)
	{
		j = 0;
		while (j < map_dimensions.columns)
		{
			if (iso_matrix[0][i][j] < map_limits->min_x_value)
				map_limits->min_x_value = iso_matrix[0][i][j];
			if (iso_matrix[0][i][j] > map_limits->max_x_value)
				map_limits->max_x_value = iso_matrix[0][i][j];
			if (iso_matrix[1][i][j] < map_limits->min_y_value)
				map_limits->min_y_value = iso_matrix[1][i][j];
			if (iso_matrix[1][i][j] > map_limits->max_y_value)
				map_limits->max_y_value = iso_matrix[1][i][j];
			j++;
		}
		i++;
	}
}
