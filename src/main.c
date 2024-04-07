/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:05:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/07 17:48:16 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_matrix_cell	**matrix;
	t_mlx_data		window;
	char			*filename;
	int				amount_of_rows;
	int				amount_of_columns;

	if (argc == 2)
	{
		filename = get_filename(argv[1]);
		amount_of_columns = calculate_amount_of_columns(filename, 0);
		amount_of_rows = calculate_amount_of_rows(filename);
		matrix = make_matrix(argv[1]);
		print_matrix(matrix, amount_of_rows, amount_of_columns);
		window = create_mlx_window();
		mlx_key_hook(window.win_ptr, handle_escape, &window);
		put_data_on_screen(&window, matrix, amount_of_rows, amount_of_columns);
		mlx_loop(window.mlx_ptr);
		free_matrix(matrix, 11);
	}
}
