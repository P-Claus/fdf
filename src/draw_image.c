/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:55:27 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/04 22:44:32 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_pixel_put(t_img *img, int y, int x, int color)
{
	int	offset;

	// calculates the offset by looking for the y-offset and x-offset
	offset = (img->line_len * x) + (y * (img->bits_per_pixel / 8));
	// it casts the newly found pointer (which is the starting point for the image) to unsigned int and give it the color
	*((unsigned int *)(offset + img->address)) = color;
}

void	put_data_on_screen(t_mlx_data *data, int color)
{
	int	row_iter;
	int	column_iter;
	int	width_of_map;
	int	height_of_map;
	int	distance_between_x_points;
	int	distance_between_y_points;
	int	amount_of_columns;
	int	amount_of_rows;

	amount_of_columns = 10;
	amount_of_rows = 5;
	// need to calculate how many points there need to be per row
	// amount of columns
	// calculate how many points per column
	// amount of rows
	// calculate where it needs to be
	width_of_map = WIDTH - 100;
	distance_between_x_points = width_of_map / amount_of_columns;
	column_iter = distance_between_x_points;
	ft_printf("The distance between x points is: %d\n",
		distance_between_x_points);
	height_of_map = HEIGHT - 100;
	distance_between_y_points = height_of_map / amount_of_rows;
	row_iter = distance_between_y_points;
	ft_printf("The distance between y points is: %d\n",
		distance_between_y_points);
	// width - offset(100) = 600
	// 600 / amount of columns = space between the columns (=> x coordinate)
	// height - offset(100) = 600
	// 600 / amount of rows = space between rows (=> y coordinate?)
	// calculate the distance between the points based on teh amount of points there need to be on each axis
	while (row_iter <= height_of_map)
	{
		while (column_iter <= width_of_map)
		{
			my_pixel_put(&data->img, column_iter, row_iter, color);
			ft_printf("column_iter is: %d\n", column_iter);
			column_iter += distance_between_x_points;
		}
		column_iter = distance_between_x_points;
		row_iter += distance_between_y_points;
	}
}

// function to run everytime the ESC key is pressed
int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	else if (keysym == XK_r)
	{
		printf("The (r) key has been pressed\n\n");
		put_data_on_screen(data, 0xFF0000);
	}
	else if (keysym == XK_g)
	{
		printf("The (g) key has been pressed\n\n");
		put_data_on_screen(data, 0x00FF00);
	}
	// function to put the image on the screen
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0);
	return (0);
}

void	create_mlx_window(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return ;
	data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT, WIDTH, "fdf");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return ;
	}
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.address = mlx_get_data_addr(data.img.img_ptr,
			&data.img.bits_per_pixel, &data.img.line_len, &data.img.endian);
	// this fills all the data in the struct and returns a pointer to the pixels and those are the ones we will manipulate
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.img_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr); // to remove the window
	mlx_destroy_display(data.mlx_ptr);              // to remove the connection
	free(data.mlx_ptr);
}
