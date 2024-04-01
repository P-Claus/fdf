/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:37:41 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/01 10:39:41 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_split(char **split_array)
{
	int	split_iter;

	split_iter = 0;
	while (split_array[split_iter])
	{
		ft_printf("The string is: %s\n", split_array[split_iter]);
		split_iter++;
	}
}
