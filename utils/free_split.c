/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:27:21 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/01 10:36:12 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_split(char **split_array)
{
	int split_iter = 0;

	while (split_array[split_iter])
	{
		free(split_array[split_iter]);
		split_iter++;
	}
	free(split_array);
}