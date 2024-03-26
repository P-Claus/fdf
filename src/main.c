/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:05:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/26 10:48:22 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	// int fd;
	const char *filename;
	const char *include_path;

	if (argc == 2)
	{
		include_path = "./maps/";
		filename = ft_strjoin(include_path, (const char *)argv[1]);
		ft_printf("The filename is: %s\n", filename);
		free((void *)filename);
	}
}