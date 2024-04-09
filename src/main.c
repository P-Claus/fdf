/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:05:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/09 22:00:02 by pclaus           ###   ########.fr       */
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

	////////
	///////
	validate_input(argc, argv[1]);
	filename = get_filename(argv[1]);
	map_dimensions = get_map_dimensions(filename);
	ft_printf("Rows: %d Columns: %d\n", map_dimensions.rows,
		map_dimensions.columns);
	window = create_mlx_window();
	matrix = make_matrix(argv[1]);
	map_data = calculate_tile_size(map_dimensions, matrix);
	iso_matrix = create_isometric_map(matrix, map_data, map_dimensions);
	calculate_map_limits(iso_matrix, map_dimensions, &map_limits);
	map_data.map = &map_dimensions;
	draw_map(matrix, iso_matrix, &window, map_data);
	mlx_key_hook(window.win_ptr, handle_escape, &window);
	mlx_loop(window.mlx_ptr);
	////////// above this line is checked and should be correct
	/*
	put_data_on_screen(&window, matrix, amount_of_rows, amount_of_columns);
	free_matrix(matrix, 11);
	*/
	free(filename);
}
