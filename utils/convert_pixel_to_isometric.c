/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pixel_to_isometric.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:38:29 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/08 16:42:48 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pixel	convert_pixel_to_isometric(t_pixel pixel, t_line_data line_data)
{
	t_pixel	iso_pixel;
	
	iso_pixel.x = (pixel.x - pixel.y);
	iso_pixel.y = (pixel.x + pixel.y) / 2 - line_data.z;
	return (iso_pixel);	
}
