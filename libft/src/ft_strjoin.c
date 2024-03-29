/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:39:47 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/29 16:35:10 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *dst, char const *src)
{
	int		total_length;
	int		index;
	int		index_dst;
	int		index_src;
	char	*new_string;

	index = 0;
	index_dst = 0;
	index_src = 0;
	total_length = ft_strlen(dst) + ft_strlen(src);
	new_string = (char *)malloc((total_length + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	while (dst[index_dst] != '\0')
		new_string[index++] = dst[index_dst++];
	while (src[index_src] != '\0')
		new_string[index++] = src[index_src++];
	new_string[index++] = '\0';
	return (new_string);
}
