/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:50:06 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/24 17:01:44 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	gnl_ft_strlen(const char *s);
char	*gnl_ft_strchr(char *str, int c);
void	*gnl_ft_calloc(size_t num_elements, size_t element_size);
char	*gnl_ft_strjoin(char *dst, char *src);

#endif
