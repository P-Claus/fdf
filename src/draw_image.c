/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:55:27 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/05 14:32:22 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (x * img->line_len + y * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_data_on_screen(t_mlx_data *data, t_matrix_cell **matrix,
		int amount_of_rows, int amount_of_columns)
{
	int	row_iter;
	int	column_iter;
	int	width_of_map;
	int	height_of_map;
	int	distance_between_x_points;
	int	distance_between_y_points;
	int	i;
	int	j;

	i = 0;
	j = 0;
	// need to calculate how many points there need to be per row
	// amount of columns
	// calculate how many points per column
	// amount of rows
	// calculate where it needs to be
	print_matrix(matrix, amount_of_rows, amount_of_columns);
	width_of_map = WIDTH - 200;
	distance_between_x_points = width_of_map / amount_of_columns;
	column_iter = distance_between_x_points;
	ft_printf("The distance between x points is: %d\n",
		distance_between_x_points);
	height_of_map = HEIGHT - 200;
	distance_between_y_points = height_of_map / amount_of_rows;
	row_iter = distance_between_y_points;
	ft_printf("The distance between y points is: %d\n",
		distance_between_y_points);
	// width - offset(100) = 600
	// 600 / amount of columns = space between the columns (=> x coordinate)
	// height - offset(100) = 600
	// 600 / amount of rows = space between rows (=> y coordinate?)
	// calculate the distance between the points based on teh amount of points there need to be on each axis
	while (row_iter <= height_of_map && i < amount_of_rows)
	{
		while (column_iter <= width_of_map && j < amount_of_columns)
		{
			my_pixel_put(&data->img, row_iter, column_iter, matrix[i][j].color);
			column_iter += distance_between_x_points;
			j++;
		}
		column_iter = distance_between_x_points;
		row_iter += distance_between_y_points;
		j = 0;
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0);
}
