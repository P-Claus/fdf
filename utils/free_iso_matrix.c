/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_iso_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:24:29 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/16 19:01:34 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_iso_matrix(int ***iso_matrix, int amount_of_rows)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= 1)
	{
		while (j < amount_of_rows)
		{
			if (iso_matrix[i][j] != NULL)
			{
				free(iso_matrix[i][j]);
				iso_matrix[i][j] = NULL;
			}
			j++;
		}
		j = 0;
		free(iso_matrix[i]);
		iso_matrix[i] = NULL;
		i++;
	}
	free(iso_matrix);
}
