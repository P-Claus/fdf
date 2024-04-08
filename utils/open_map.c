/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:11:44 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/08 22:12:55 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	open_map(char *filename)
{
	int fd;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	return (fd);
}