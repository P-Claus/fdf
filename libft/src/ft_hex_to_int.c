/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:33:47 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/05 12:19:59 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_hex_string_to_int(char *hex_string)
{
	int		number;
	char	c;

	number = 0;
	if (hex_string[0] == '0' && (hex_string[1] == 'x' || hex_string[1] == 'X'))
		hex_string += 2;
	while (*hex_string)
	{
		c = *hex_string;
		number *= 16;
		if (c >= '0' && c <= '9')
			number += c - '0';
		else if (c >= 'a' && c <= 'f')
			number += c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			number += c - 'A' + 10;
		hex_string++;
	}
	return (number);
}
