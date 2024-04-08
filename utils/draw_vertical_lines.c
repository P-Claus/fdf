/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:47:31 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/08 12:44:37 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_vertical_lines(t_mlx_data *data, t_matrix_cell **matrix,
		t_map_dimensions map_dimensions, t_distance_between_points distance)
{
	int			i;
	int			j;
	t_line_data	line_data;

	i = 0;
	j = 0;
	while (i < map_dimensions.rows - 1)
	{
		while (j < map_dimensions.columns)
		{
			line_data.data = data;
			line_data.matrix = matrix;
			line_data.i = i;
			line_data.j = j;
			line_data.distance = distance;
			line_data.color = matrix[i][j].color;
			line_data.z = matrix[i][j].value;
			draw_v_line(line_data, map_dimensions);
			j++;
		}
		j = 0;
		i++;
	}
}
void	draw_v_line(t_line_data line_data, t_map_dimensions map_dimensions)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	(void)map_dimensions;
	dx = 0;
	dy = line_data.distance.y;
	p = 2 * dx - dy;
	x = line_data.j * line_data.distance.x + 50;
	y = line_data.i * line_data.distance.y + 50;
	while (y < (line_data.i + 1) * line_data.distance.y + 50)
	{
		my_pixel_put(&line_data.data->img, x, y, line_data.color);
		y++;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			x++;
			p = p + 2 * dx - 2 * dy;
		}
	}
}
