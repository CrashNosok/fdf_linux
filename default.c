#include "fdf.h"

void	create_arrays(t_fdf *data)
{
	int i;

	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	data->colors = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int*)malloc(sizeof(int) * (data->width + 1));
		data->colors[i] = (int*)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	data->z_matrix[i] = NULL;
	data->colors[i] = NULL;
}

void	fill_color_array(t_fdf *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->colors[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	fill_z_array(t_fdf *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->z_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	set_default(char *file_name, t_fdf *data)
{
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	create_arrays(data);
	fill_color_array(data);
	fill_z_array(data);
	data->zoom = set_zoom(data);
	data->is_isometric = 1;
	data->angle = 0.8;
	data->x_angle = 0;
	data->y_angle = 0;
	data->z_angle = 0;
	data->win_x = 1500;
	data->win_y = 1000;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
		data->win_x, data->win_y, "FDF");
}
