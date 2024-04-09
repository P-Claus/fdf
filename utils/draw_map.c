/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:08:05 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/09 21:58:38 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_line(t_mlx_data *window, t_line_data *line_data, int color)
{
	int	e2;

	while (line_data->x0 != line_data->x1 || line_data->y0 != line_data->y1)
	{
		my_pixel_put(&window->img, line_data->x0, line_data->y0, color);
		e2 = 2 * line_data->err;
		if (e2 > -line_data->dy)
		{
			line_data->err -= line_data->dy;
			line_data->x0 += line_data->x_direction;
		}
		if (e2 < line_data->dx)
		{
			line_data->err += line_data->dx;
			line_data->y0 += line_data->y_direction;
		}
	}
}

static void	draw_horizontal_lines(t_matrix_cell **matrix, int ***iso_matrix,
		t_mlx_data *window, t_map_data map_data)
{
	t_line_data	line_data;
	int			i;
	int			j;

	i = 0;
	while (i < map_data.map->rows)
	{
		j = 0;
		while (j < map_data.map->columns - 1)
		{
			line_data.x0 = iso_matrix[0][i][j] + map_data.offset_x;
			line_data.y0 = iso_matrix[1][i][j] + map_data.offset_y;
			line_data.x1 = iso_matrix[0][i][j + 1] + map_data.offset_x;
			line_data.y1 = iso_matrix[1][i][j + 1] + map_data.offset_y;
			init_line_data(&line_data);
			draw_line(window, &line_data, matrix[i][j].color);
			j++;
		}
		i++;
	}
}

static void	draw_vertical_lines(t_matrix_cell **matrix, int ***iso_matrix,
		t_mlx_data *window, t_map_data map_data)
{
	t_line_data	line_data;
	int			i;
	int			j;

	i = 0;
	while (i < map_data.map->rows - 1)
	{
		j = 0;
		while (j < map_data.map->columns)
		{
			line_data.x0 = iso_matrix[0][i][j] + map_data.offset_x;
			line_data.y0 = iso_matrix[1][i][j] + map_data.offset_y;
			line_data.x1 = iso_matrix[0][i + 1][j] + map_data.offset_x;
			line_data.y1 = iso_matrix[1][i + 1][j] + map_data.offset_y;
			init_line_data(&line_data);
			draw_line(window, &line_data, matrix[i][j].color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_matrix_cell **matrix, int ***iso_matrix, t_mlx_data *window,
		t_map_data map_data)
{
	draw_horizontal_lines(matrix, iso_matrix, window, map_data);
	draw_vertical_lines(matrix, iso_matrix, window, map_data);
}