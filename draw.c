#include "fdf.h"

void			isometric(float *x, float *y, int z, double a)
{
	*x = (*x - *y) * cos(a);
	*y = (*x + *y) * sin(a) - z;
}

void			prepare_coords(t_coords *coords, int x, int y, t_fdf *data)
{
	coords->x = x;
	coords->y = y;
	coords->z = data->z_matrix[(int)coords->y][(int)coords->x];
	coords->color = get_default_color(coords->y, coords->x, coords->z, data);
	coords->x *= data->zoom;
	coords->y *= data->zoom;
	rotate_x(&coords->y, &coords->z, data->x_angle);
	rotate_y(&coords->x, &coords->z, data->y_angle);
	rotate_z(&coords->x, &coords->y, data->z_angle);
	if (data->is_isometric)
		isometric(&coords->x, &coords->y, coords->z, data->angle);
	coords->x += data->shift_x;
	coords->y += data->shift_y;
}

void			bresenham(t_coords coord_1, t_coords coord_2, t_fdf *data)
{
	float		x_step;
	float		y_step;
	int			max;
	t_coords	start;
	t_coords	delta;

	max = max_val(mod(coord_2.x - coord_1.x), mod(coord_2.y - coord_1.y));
	x_step = (coord_2.x - coord_1.x) / max;
	y_step = (coord_2.y - coord_1.y) / max;
	delta.x = x_step;
	delta.y = y_step;
	start = coord_1;
	while ((int)(coord_1.x - coord_2.x) || (int)(coord_1.y - coord_2.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, coord_1.x, coord_1.y,
			get_color(coord_1, start, coord_2, delta));
		coord_1.x += x_step;
		coord_1.y += y_step;
	}
}

void			draw(t_coords *coord_1, t_coords *coord_2, t_fdf *data)
{
	int			x;
	int			y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			prepare_coords(coord_1, x, y, data);
			if (x < data->width - 1)
			{
				prepare_coords(coord_2, x + 1, y, data);
				bresenham(*coord_1, *coord_2, data);
			}
			if (y < data->height - 1)
			{
				prepare_coords(coord_2, x, y + 1, data);
				bresenham(*coord_1, *coord_2, data);
			}
			x++;
		}
		y++;
	}
}
