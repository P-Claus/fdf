/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:39:47 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/29 15:44:01 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *dst, char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!dst)
	{
		dst = (char *)malloc(1 * sizeof(char));
		dst[0] = '\0';
	}
	if (!dst || !src)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(dst) + ft_strlen(src)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (dst)
		while (dst[++i] != '\0')
			str[i] = dst[i];
	while (src[j] != '\0')
		str[i++] = src[j++];
	str[ft_strlen(dst) + ft_strlen(src)] = '\0';
	free(dst);
	return (str);
}
