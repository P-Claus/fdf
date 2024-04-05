/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:23:57 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/05 09:24:29 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx_data	create_mlx_window(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	// if (!data.mlx_ptr)
	// return ;
	data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT, WIDTH, "fdf");
	// if (!data.win_ptr)
	//{
	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);
	// return ;
	//}
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.address = mlx_get_data_addr(data.img.img_ptr,
			&data.img.bits_per_pixel, &data.img.line_len, &data.img.endian);
	// this fills all the data in the struct and returns a pointer to the pixels and those are the ones we will manipulate
	// mlx_key_hook(data.win_ptr, handle_escape, &data);
	// mlx_loop(data.mlx_ptr);
	return (data);
}
