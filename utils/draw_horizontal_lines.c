/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_horizontal_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 09:52:54 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/07 15:27:09 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_horizontal_lines(t_mlx_data *data, t_matrix_cell **matrix,
		t_map_dimensions map_dimensions, t_distance_between_points distance)
{
	int			i;
	int			j;
	t_line_data	line_data;

	i = 0;
	j = 0;
	while (i < map_dimensions.rows)
	{
		while (j < map_dimensions.columns - 1)
		{
			line_data.data = data;
			line_data.matrix = matrix;
			line_data.i = i;
			line_data.j = j;
			line_data.distance = distance;
			line_data.color = matrix[i][j].color;
			draw_h_line(line_data);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_h_line(t_line_data line_data)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = line_data.distance.x;
	dy = 0;
	p = 2 * dy - dx;
	x = line_data.j * line_data.distance.x + 50;
	y = line_data.i * line_data.distance.y + 50;
	while (x < (line_data.j + 1) * line_data.distance.x + 50)
	{
		my_pixel_put(&line_data.data->img, x, y, line_data.color);
		x++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			x++;
			p = p + 2 * dy - 2 * dx;
		}
	}
}
