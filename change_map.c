#include "fdf.h"

int				is_key(int key)
{
	if (key == 123 || key == 126 || key == 124 || key == 125 ||
		key == 2 || key == 14 ||
		key == 1 || key == 13 ||
		key == 49 || key == 53 ||
		key == 15 || key == 17 || key == 16 ||
		key == 3 || key == 5 || key == 4 ||
		key == 0 || key == 12)
		return (1);
	return (0);
}

void			redraw_map(t_fdf *data)
{
	t_coords	coord_1;
	t_coords	coord_2;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(&coord_1, &coord_2, data);
}

void			close_win(t_fdf *data)
{
	int i;

	i = 0;
	while (i <= data->height)
	{
		free(data->z_matrix[i]);
		free(data->colors[i]);
		i++;
	}
	free(data->colors);
	free(data->z_matrix);
	free(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

void			rotate_map(int key, t_fdf *data)
{
	if (key == 15)
		data->x_angle += 0.1;
	if (key == 17)
		data->y_angle += 0.1;
	if (key == 16)
		data->z_angle += 0.1;
	if (key == 3)
		data->x_angle -= 0.1;
	if (key == 5)
		data->y_angle -= 0.1;
	if (key == 4)
		data->z_angle -= 0.1;
}

void			change_size(t_fdf *data, float koef)
{
	if (data->zoom < 60)
		data->zoom += koef;
	if (data->zoom >= 60)
		data->zoom -= koef;
}
