/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:59:18 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/16 19:31:19 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_str_is_numeric(char *str)
{
	int	count;

	count = 0;
	while (str[count] && str[count] != '\0')
	{
		if ((str[count] >= '0') && (str[count] <= '9'))
			count++;
		else
			return (0);
	}
	return (1);
}
