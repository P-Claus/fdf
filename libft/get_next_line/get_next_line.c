/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:30 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/24 17:02:44 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*remove_line_from_stash(char *stash)
{
	int		count;
	int		i;
	char	*string;

	count = 0;
	while (stash[count] && stash[count] != '\n')
		count++;
	if (!stash[count])
	{
		free(stash);
		return (NULL);
	}
	count++;
	string = gnl_ft_calloc((gnl_ft_strlen(stash) - count + 1), sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (stash[count])
		string[i++] = stash[count++];
	free(stash);
	return (string);
}

static char	*put_stash_in_line(char *stash)
{
	int		count;
	char	*line;

	count = 0;
	if (!stash[count])
		return (NULL);
	line = gnl_ft_calloc((gnl_ft_strlen(stash) + 1), sizeof(char));
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
	while (!gnl_ft_strchr(stash, '\n') && bytes_read != 0)
	{
		buffer = gnl_ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		stash = gnl_ft_strjoin(stash, buffer);
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
	stash = remove_line_from_stash(stash);
	if (stash && *stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
