/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_isometric_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:18:24 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/10 17:09:58 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_iso_pro(t_pixel_coordinates pixel_coordinates,
		int *iso_x_coordinate, int *iso_y_coordinate, t_map_data map_data)
{
	*iso_x_coordinate = (int)(((sqrt(2) / 2) * (pixel_coordinates.y
					- pixel_coordinates.x)) * map_data.tile_size);
	*iso_y_coordinate = (int)(((sqrt(2) / 2) * (pixel_coordinates.y
					+ pixel_coordinates.x) - sqrt(2.0 / 3.0)
				* pixel_coordinates.z * map_data.scale_of_height)
			* map_data.tile_size);
}

int	***create_isometric_map(t_matrix_cell **matrix, t_map_data map_data,
		t_map_dimensions map_dimensions)
{
	int					***i_map;
	t_pixel_coordinates	p_coords;
	int					i;
	int					j;

	i_map = (int ***)malloc(sizeof(int **) * 2);
	i_map[0] = (int **)malloc(sizeof(int *) * map_dimensions.rows);
	i_map[1] = (int **)malloc(sizeof(int *) * map_dimensions.rows);
	i = 0;
	while (i < map_dimensions.rows)
	{
		i_map[0][i] = (int *)malloc(sizeof(int) * map_dimensions.columns);
		i_map[1][i] = (int *)malloc(sizeof(int) * map_dimensions.columns);
		j = 0;
		while (j < map_dimensions.columns)
		{
			p_coords.x = i;
			p_coords.y = j;
			p_coords.z = matrix[i][j].value;
			get_iso_pro(p_coords, &i_map[0][i][j], &i_map[1][i][j], map_data);
			j++;
		}
		i++;
	}
	return (i_map);
}
