/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:05:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/22 22:21:32 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map_dimensions	map_dimensions;
	char				*filename;
	t_mlx_data			w;
	t_map_info			map_info;
	t_arrays			arr;

	validate_input(argc, argv[1]);
	filename = get_filename(argv[1]);
	map_dimensions = get_map_dimensions(filename);
	free(filename);
	w = create_mlx_window();
	arr.matrix = make_matrix(argv[1]);
	map_info.data = calculate_tile_size(map_dimensions, arr.matrix);
	arr.iso_matrix = create_isometric_map(arr.matrix, map_info.data,
			map_dimensions);
	calculate_map_limits(arr.iso_matrix, map_dimensions, &map_info.limits);
	map_info.data.map = &map_dimensions;
	map_info.data = calculate_offsets(map_info.limits, map_info.data);
	draw_map(arr.matrix, arr.iso_matrix, &w, map_info.data);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img.img_ptr, 0, 0);
	free_matrix(arr.matrix, map_dimensions.rows);
	free_iso_matrix(arr.iso_matrix, map_dimensions.rows);
	mlx_key_hook(w.win_ptr, handle_escape, &w);
	mlx_hook(w.win_ptr, 17, 1L << 0, close_mlx_event, &w);
	mlx_loop(w.mlx_ptr);
}
