/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:05:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/16 19:13:48 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map_dimensions	map_dimensions;
	char				*filename;
	t_mlx_data			window;
	t_matrix_cell		**matrix;
	t_map_data			map_data;
	int					***iso_matrix;
	t_map_limits		map_limits;

	validate_input(argc, argv[1]);
	filename = get_filename(argv[1]);
	map_dimensions = get_map_dimensions(filename);
	free(filename);
	window = create_mlx_window();
	matrix = make_matrix(argv[1]);
	map_data = calculate_tile_size(map_dimensions, matrix);
	iso_matrix = create_isometric_map(matrix, map_data, map_dimensions);
	calculate_map_limits(iso_matrix, map_dimensions, &map_limits);
	map_data.map = &map_dimensions;
	map_data = calculate_offsets(map_limits, map_data);
	draw_map(matrix, iso_matrix, &window, map_data);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.img.img_ptr,
		0, 0);
	free_matrix(matrix, map_dimensions.rows);
	free_iso_matrix(iso_matrix, map_dimensions.rows);
	mlx_key_hook(window.win_ptr, handle_escape, &window);
	mlx_hook(window.win_ptr, 17, 1L << 0, close_mlx_event, &window);
	mlx_loop(window.mlx_ptr);
}
