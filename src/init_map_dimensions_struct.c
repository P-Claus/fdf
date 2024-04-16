/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_dimensions_struct.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:14:31 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/16 19:34:10 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map_dimensions	init_map_dimensions_struct(void)
{
	t_map_dimensions	map_dimensions;

	map_dimensions.rows = 0;
	map_dimensions.columns = 0;
	return (map_dimensions);
}
