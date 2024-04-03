/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:05:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/03 10:07:14 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		calculate_matrix(argv[1]);
		create_mlx_window();
	}
}
