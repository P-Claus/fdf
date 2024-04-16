/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:25:28 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/09 21:29:48 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_line_data(t_line_data *line_data)
{
	line_data->dx = abs(line_data->x1 - line_data->x0);
	line_data->dy = abs(line_data->y1 - line_data->y0);
	if (line_data->x0 < line_data->x1)
		line_data->x_direction = 1;
	else
		line_data->x_direction = -1;
	if (line_data->y0 < line_data->y1)
		line_data->y_direction = 1;
	else
		line_data->y_direction = -1;
	line_data->err = line_data->dx - line_data->dy;
}
