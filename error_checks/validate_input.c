/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:42:04 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/23 15:45:54 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	validate_input(int argc, char *filename)
{
	if (argc == 1)
	{
		ft_putstr_color_fd(YELLOW, "You need to enter a map as argument\n", 1);
		ft_putstr_color_fd(YELLOW, "Format: ./fdf <filename>.fdf\n", 1);
		exit(0);
	}
	if (argc != 2)
	{
		ft_putstr_color_fd(YELLOW, "You can only load one map\n", 1);
		ft_putstr_color_fd(YELLOW, "Format: ./fdf <filename>.fdf\n", 1);
		exit(0);
	}
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".fdf", 4))
	{
		ft_putstr_color_fd(RED,
			"The map you want to load must have the .fdf extension\n", 1);
		exit(0);
	}
}
