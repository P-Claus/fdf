/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:05:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/08 22:26:53 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map_dimensions	map_dimensions;
	char				*filename;

	// t_matrix_cell		**matrix;
	// t_mlx_data			window;
	////////
	///////
	validate_input(argc, argv[1]);
	filename = get_filename(argv[1]);
	map_dimensions = get_map_dimensions(filename);
	ft_printf("Rows: %d Columns: %d\n", map_dimensions.rows,
		map_dimensions.columns);
	////////// above this line is checked and should be correct
	/*
	matrix = make_matrix(argv[1]);
	window = create_mlx_window();
	mlx_key_hook(window.win_ptr, handle_escape, &window);
	put_data_on_screen(&window, matrix, amount_of_rows, amount_of_columns);
	mlx_loop(window.mlx_ptr);
	free_matrix(matrix, 11);
	*/
	free(filename);
}
