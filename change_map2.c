#include "fdf.h"

void	change_projection(t_fdf *data)
{
	data->x_angle = 0;
	data->y_angle = 0;
	data->z_angle = 0;
	data->is_isometric = !(data->is_isometric);
}

void	updown_multi(t_fdf *data, float koef)
{
	int i;
	int j;

	i = 0;
	if (data->max_z * koef > 700 || data->min_z * koef < -700)
		return ;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->z_matrix[i][j] != 0)
				data->z_matrix[i][j] *= koef;
			j++;
		}
		i++;
	}
	data->max_z = find_max_z(data, data->z_matrix[0][0]);
	data->min_z = find_min_z(data, data->z_matrix[0][0]);
}

void	updown(t_fdf *data, float koef)
{
	int i;
	int j;

	i = 0;
	if (data->max_z + koef > 700 || data->min_z + koef < -700)
		return ;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->z_matrix[i][j] != 0)
			{
				if (data->z_matrix[i][j] + koef == 0)
					data->z_matrix[i][j] += koef + 1;
				else
					data->z_matrix[i][j] += koef;
			}
			j++;
		}
		i++;
	}
	data->max_z = find_max_z(data, data->z_matrix[0][0]);
	data->min_z = find_min_z(data, data->z_matrix[0][0]);
}

void	move_map(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	else if (key == 125)
		data->shift_y += 10;
	else if (key == 124)
		data->shift_x += 10;
	else if (key == 123)
		data->shift_x -= 10;
}
