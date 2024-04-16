/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_dimensions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:29:05 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/10 15:36:09 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	calculate_amount_of_rows(char *filename)
{
	int		fd;
	int		amount_of_rows;
	char	*result;

	amount_of_rows = 0;
	fd = open(filename, O_RDONLY);
	result = get_next_line(fd);
	while (result != NULL)
	{
		free(result);
		result = get_next_line(fd);
		amount_of_rows++;
	}
	free(result);
	close(fd);
	return (amount_of_rows);
}

int	calculate_amount_of_columns(char *filename, int iter)
{
	int		fd;
	int		amount_of_columns;
	char	**split;
	char	*result;

	amount_of_columns = 0;
	fd = open(filename, O_RDONLY);
	result = get_next_line(fd);
	split = ft_split(result, ' ');
	while (split[iter])
	{
		amount_of_columns++;
		iter++;
	}
	iter = 0;
	while (split[iter])
	{
		free(split[iter]);
		iter++;
	}
	free(split);
	free(result);
	close(fd);
	return (amount_of_columns);
}

t_map_dimensions	get_map_dimensions(char *filename)
{
	t_map_dimensions	map_dimensions;

	map_dimensions = init_map_dimensions_struct();
	map_dimensions.rows = calculate_amount_of_rows(filename);
	map_dimensions.columns = calculate_amount_of_columns(filename, 0);
	return (map_dimensions);
}
