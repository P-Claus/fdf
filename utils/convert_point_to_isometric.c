/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_point_to_isometric.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:38:29 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/07 20:50:42 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	convert_point_to_isometric(int *x, int *y, int z)
{
	int	original_x;
	int	original_y;

	original_x = *x;
	original_y = *y;
	*x = (original_x - original_y) * cos(0.523599);
	*y = (original_x + original_y) * sin(0.523599) - z;
}
