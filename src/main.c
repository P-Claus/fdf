/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:05:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/26 16:52:23 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <string.h>

int main(int argc, char **argv)
{
	// int fd;
	const char *filename;
	const char *include_path;
	int fd;
	char *result;
	char **split_array;
	int	iter = 0;

	if (argc == 2)
	{
		include_path = "./maps/";
		filename = ft_strjoin(include_path, (const char *)argv[1]);
		fd = open(filename, O_RDONLY);
		result = get_next_line(fd);
		ft_printf("The result is: %s\n", result);
		split_array = ft_split(result, 32);
		while (split_array[iter])
		{
			ft_printf("%s", split_array[iter]);
			free(split_array[iter]);
			iter++;
		}
		free(split_array);
		free(result);
		close(fd);
		free((void *)filename);
	}
}