/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:06:18 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/05 12:22:41 by pclaus           ###   ########.fr       */
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
	void		*img_ptr;
	char		*address;
	int			bits_per_pixel;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx_data;

typedef struct s_matrix_cell
{
	int			value;
	int			color;
}				t_matrix_cell;

/*	UTILS	*/
t_matrix_cell	**make_matrix(char *name_of_file);
int				calculate_amount_of_columns(char *filename, int iter);
int				calculate_amount_of_rows(char *filename);
t_matrix_cell	**fill_matrix(int amount_of_rows, int amount_of_columns,
					char *filename);
t_matrix_cell	**allocate_matrix(int amount_of_rows, int amount_of_columns);
void			free_matrix(t_matrix_cell **matrix, int amount_of_rows);
void			print_matrix(t_matrix_cell **matrix, int amount_of_rows,
					int amount_of_columns);
void			free_split(char **split_array);
void			print_split(char **split_array, int amount_of_columns);
void			split_for_color(t_matrix_cell **matrix, char **split_result,
					int split_iter, int iter);
void			put_data_into_matrix(t_matrix_cell **matrix, char *result,
					int iter, int amount_of_columns);
int				check_amount_of_columns_in_matrix(t_matrix_cell **matrix);
char			*get_filename(char *name_of_file);

/*	MLX FUNCTIONs	*/
t_mlx_data		create_mlx_window(void);
int				handle_escape(int keysym, t_mlx_data *mlx_data);

int				close_mlx_event(t_mlx_data *mlx_data);
void			put_data_on_screen(t_mlx_data *data, t_matrix_cell **matrix,
					int amount_of_rows, int amount_of_columns);
