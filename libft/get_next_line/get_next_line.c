/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:30 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/29 15:50:45 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*put_stash_in_line(char *stash)
{
	int		count;
	char	*line;

	count = 0;
	if (!stash[count])
		return (NULL);
	line = ft_calloc((ft_strlen(stash) + 1), sizeof(char));
	if (!line)
		return (NULL);
	while (stash[count] && stash[count] != '\n')
	{
		line[count] = stash[count];
		count++;
	}
	if (stash[count] == '\n')
		line[count] = stash[count];
	return (line);
}

static char	*fill_stash(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		stash = ft_strjoin(stash, buffer);
		free(buffer);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = put_stash_in_line(stash);
	free(stash);
	stash = NULL;
	return (line);
}
