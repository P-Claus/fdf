/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:04:55 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/22 21:42:25 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*get_filename(char *name_of_file)
{
	char	*filename;
	char	*include_path;

	include_path = "./maps/";
	filename = ft_strjoin(include_path, name_of_file);
	return (filename);
}
