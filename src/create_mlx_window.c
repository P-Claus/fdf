/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:23:57 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/10 16:14:17 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx_data	create_mlx_window(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.address = mlx_get_data_addr(data.img.img_ptr,
			&data.img.bits_per_pixel, &data.img.line_len, &data.img.endian);
	data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT, WIDTH, "fdf");
	return (data);
}
