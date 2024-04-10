/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_offsets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:48:29 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/10 15:45:58 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map_data	calculate_offsets(t_map_limits map_limits, t_map_data map_data)
{
	int iso_box_width;
	int iso_box_height;

	iso_box_width = map_limits.max_x_value - map_limits.min_x_value;
	iso_box_height = map_limits.max_y_value - map_limits.min_y_value;
	map_data.offset_x = (WIDTH - iso_box_width) / 2 - map_limits.min_x_value;
	map_data.offset_y = (HEIGHT - iso_box_height) / 2 - map_limits.min_y_value;
	return (map_data);
}