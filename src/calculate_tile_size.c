/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_tile_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:51:43 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/16 19:43:34 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	find_min_height(t_map_dimensions map_dimensions,
		t_matrix_cell **matrix)
{
	int	min_height;
	int	i;
	int	j;

	min_height = matrix[0][0].value;
	i = 0;
	j = 0;
	while (i < map_dimensions.rows)
	{
		while (j < map_dimensions.columns)
		{
			if (matrix[i][j].value < min_height)
				min_height = matrix[i][j].value;
			j++;
		}
		j = 0;
		i++;
	}
	return (min_height);
}

static int	find_max_height(t_map_dimensions map_dimensions,
		t_matrix_cell **matrix)
{
	int	max_height;
	int	i;
	int	j;

	max_height = matrix[0][0].value;
	i = 0;
	j = 0;
	while (i < map_dimensions.rows)
	{
		while (j < map_dimensions.columns)
		{
			if (matrix[i][j].value > max_height)
				max_height = matrix[i][j].value;
			j++;
		}
		j = 0;
		i++;
	}
	return (max_height);
}

t_map_data	calculate_tile_size(t_map_dimensions map_dimensions,
		t_matrix_cell **matrix)
{
	t_map_data	map_data;
	int			x_length_of_tile;
	int			y_length_of_tile;
	int			max_height;
	int			min_height;

	map_data.scale_of_height = 0.3;
	min_height = find_min_height(map_dimensions, matrix);
	max_height = find_max_height(map_dimensions, matrix);
	x_length_of_tile = (WIDTH - 250) / map_dimensions.columns;
	y_length_of_tile = (HEIGHT - 250) / (map_dimensions.rows + max_height
			* map_data.scale_of_height - min_height * map_data.scale_of_height);
	map_data.tile_size = find_minimum(x_length_of_tile, y_length_of_tile);
	while (map_data.tile_size < 1)
	{
		map_data.scale_of_height /= 2;
		x_length_of_tile = (WIDTH - 250) / map_dimensions.columns;
		y_length_of_tile = (HEIGHT - 250) / (map_dimensions.rows + max_height
				* map_data.scale_of_height - min_height
				* map_data.scale_of_height);
		map_data.tile_size = find_minimum(x_length_of_tile, y_length_of_tile);
	}
	return (map_data);
}
