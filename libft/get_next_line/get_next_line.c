/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:30 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/26 16:48:43 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	count = 0;
	while (s[count])
		count++;
	return (count);
}

static char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize = ft_strlen(src);
	size_t	count = 0;

	if (dstsize > 0)
	{
		while (count < srcsize && count < dstsize - 1)
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (srcsize);
}

static char	*ft_strdup(const char *src)
{
	char *dst;
	size_t	len = ft_strlen(src) + 1;

	dst = malloc(len);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, len);
	return (dst);
}

static char	*ft_strjoin(char *s1, const char *s2, size_t len)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_string;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = len;
	new_string = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, s1_len + 1);
	ft_strlcpy((new_string + s1_len), s2, s2_len + 1);
	free (s1);
	return (new_string);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;
	char	*newline;
	int	bytes_read;
	int	to_copy;

	line = ft_strdup(buffer);
	while (!(ft_strchr(line, '\n')) && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer, bytes_read);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpy(buffer, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buffer, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}
