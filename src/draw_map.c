/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:08:05 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/10 17:04:41 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	get_color(int height)
{
	if (height > 100)
		return (0xFFFFFF);
	else if (height > 50)
		return (0x402400);
	else if (height > 30)
		return (0x9A5700);
	else if (height > 10)
		return (0x009A00);
	else if (height > 0)
		return (0x00FF00);
	else
		return (0x0000FF);
}

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
			draw_line(window, &line_data, get_color(matrix[i][j].value));
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
			draw_line(window, &line_data, get_color(matrix[i][j].value));
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