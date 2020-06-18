#include "fdf.h"

int				is_key(int key)
{
	// q        113
    // a        97
    // r        114         15
    // t        116         17
    // y        121         16
    // f        102         3
    // g        103         5
    // h        104         4
    // esc      65307       53
    // space    32          49
    // w        119         13
    // s        115         1
    // e        101         14
    // d        100         2
    // left     65361       123
    // up       65362       126
    // right    65363       124
    // down     65364       125
	if (key == 65361 || key == 65362 || key == 65363 || key == 65364 ||
        key == 100 || key == 101 ||
        key == 115 || key == 119 ||
        key == 32 || key == 65307 ||
        key == 114 || key == 116 || key == 121 ||
        key == 102 || key == 103 || key == 104 ||
        key == 113 || key == 97)
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
	if (key == 114)
		data->x_angle += 0.1;
	if (key == 116)
		data->y_angle += 0.1;
	if (key == 121)
		data->z_angle += 0.1;
	if (key == 102)
		data->x_angle -= 0.1;
	if (key == 103)
		data->y_angle -= 0.1;
	if (key == 104)
		data->z_angle -= 0.1;
}

void			change_size(t_fdf *data, float koef)
{
	if (data->zoom < 60)
		data->zoom += koef;
	if (data->zoom >= 60)
		data->zoom -= koef;
}
