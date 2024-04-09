/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:55:27 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/09 10:40:41 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_data_on_screen(t_mlx_data *data, t_matrix_cell **matrix,
		int amount_of_rows, int amount_of_columns)
{
	// t_map_dimensions			map_dimensions;
	// t_distance_between_points	distance;
	// map_dimensions.rows = amount_of_rows;
	// map_dimensions.columns = amount_of_columns;
	// print_matrix(matrix, amount_of_rows, amount_of_columns);
	/*
	map_dimensions.witdh = WIDTH - 100;
	distance.x = map_dimensions.witdh / amount_of_columns;
	ft_printf("The distance between x points is: %d\n", distance.x);
	map_dimensions.height = HEIGHT - 100;
	distance.y = map_dimensions.height / amount_of_rows;
	ft_printf("The distance between y points is: %d\n", distance.y);
	draw_horizontal_lines(data, matrix, map_dimensions, distance);
	// draw_vertical_lines(data, matrix, map_dimensions, distance);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0); */
	(void)data;
	(void)matrix;
	(void)amount_of_columns;
	(void)amount_of_rows;
}
