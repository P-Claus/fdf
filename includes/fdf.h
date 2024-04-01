/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:06:18 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/30 21:59:28 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <fcntl.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct s_img
{
	void	*img_ptr;
	char	*address;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}			t_mlx_data;

/*	UTILS	*/
void		calculate_matrix(char *name_of_file);
int			calculate_amount_of_columns(char *filename);
int			calculate_amount_of_columns_with_spaces(char *filename);
int			calculate_amount_of_rows(char *filename);
void		fill_matrix(int amount_of_rows, int amount_of_columns,
				char *filename);
int			**allocate_matrix(int amount_of_rows, int amount_of_columns);