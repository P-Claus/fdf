#include "mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
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

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	// calculates the offset by looking for the y-offset and x-offset
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	// it casts the newly found pointer (which is the starting point for the image) to unsigned int and give it the color
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void	color_screen(t_mlx_data *data, int color)
{
	for (int y = 200; y < (HEIGHT - 200); ++y)
	{
		for (int x = 200; x < (WIDTH - 200); ++x)
		{
			// this function prints the pixels in the buffer
			my_pixel_put(&data->img, x, y, color);
		}
	}
}

// function to run everytime the ESC key is pressed
int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	else if (keysym == XK_r)
	{
		printf("The (r) key has been pressed\n\n");
		color_screen(data, 0xFF0000);
	}
	else if (keysym == XK_g)
	{
		printf("The (g) key has been pressed\n\n");
		color_screen(data, 0x00FF00);
	}
	// function to put the image on the screen
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT, WIDTH, "First Window");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	// Code to work with images
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	// creates a new image
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr,
			&data.img.bits_per_pixel, &data.img.line_len, &data.img.endian);
	// this fills all the data in the struct and returns a pointer to the pixels and those are the ones we will manipulate
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.img_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr); // to remove the window
	mlx_destroy_display(data.mlx_ptr);              // to remove the connection
	free(data.mlx_ptr);
}
