/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:06:18 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/16 19:37:15 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct s_img
{
	void				*img_ptr;
	char				*address;
	int					bits_per_pixel;
	int					endian;
	int					line_len;
}						t_img;

typedef struct s_mlx_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_img				img;
}						t_mlx_data;
typedef struct s_map_dimensions
{
	int					rows;
	int					columns;
}						t_map_dimensions;

typedef struct s_map_data
{
	int					tile_size;
	int					offset_x;
	int					offset_y;
	float				scale_of_height;
	t_map_dimensions	*map;
}						t_map_data;

typedef struct s_pixel_coordinates
{
	int					x;
	int					y;
	int					z;
}						t_pixel_coordinates;

typedef struct s_matrix_cell
{
	int					value;
	int					color;
}						t_matrix_cell;

typedef struct s_map_limits
{
	int					min_x_value;
	int					min_y_value;
	int					max_x_value;
	int					max_y_value;
}						t_map_limits;

///

typedef struct s_distance_between_points
{
	int					x;
	int					y;
}						t_distance_between_points;

typedef struct s_line_data
{
	int					x0;
	int					y0;
	int					x1;
	int					y1;
	int					dx;
	int					dy;
	int					x_direction;
	int					y_direction;
	int					err;
}						t_line_data;

typedef struct s_arrays
{
	t_matrix_cell		**matrix;
	int					***iso_matrix;
}						t_arrays;

/*	ERROR CHECKS	*/
void					validate_input(int argc, char *filename);

/*	SRC	*/
t_matrix_cell			**make_matrix(char *name_of_file);
int						calculate_amount_of_columns(char *filename, int iter);
int						calculate_amount_of_rows(char *filename);
t_matrix_cell			**fill_matrix(int amount_of_rows, int amount_of_columns,
							char *filename);
t_matrix_cell			**allocate_matrix(int amount_of_rows,
							int amount_of_columns);
t_map_dimensions		init_map_dimensions_struct(void);
t_map_dimensions		get_map_dimensions(char *filename);
t_map_data				calculate_tile_size(t_map_dimensions map_dimensions,
							t_matrix_cell **matrix);
int						***create_isometric_map(t_matrix_cell **matrix,
							t_map_data map_data,
							t_map_dimensions map_dimensions);
void					calculate_map_limits(int ***iso_matrix,
							t_map_dimensions map_dimensions,
							t_map_limits *map_limits);
void					init_line_data(t_line_data *line_data);
void					draw_map(t_matrix_cell **matrix, int ***iso_matrix,
							t_mlx_data *window, t_map_data map_data);
t_map_data				calculate_offsets(t_map_limits map_limits,
							t_map_data map_data);
void					split_for_color(t_matrix_cell **matrix,
							char **split_result, int split_iter, int iter);

/*	UTILS	*/
void					free_matrix(t_matrix_cell **matrix, int amount_of_rows);
void					free_iso_matrix(int ***iso_matrix, int amount_of_rows);
void					free_split(char **split_array);
void					put_data_into_matrix(t_matrix_cell **matrix,
							char *result, int iter, int amount_of_columns);
char					*get_filename(char *name_of_file);
int						find_minimum(int a, int b);

/*	MLX FUNCTIONs	*/
t_mlx_data				create_mlx_window(void);
int						handle_escape(int keysym, t_mlx_data *mlx_data);
int						close_mlx_event(t_mlx_data *mlx_data);
void					my_pixel_put(t_img *img, int x, int y, int color);
