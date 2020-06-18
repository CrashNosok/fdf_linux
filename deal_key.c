#include "fdf.h"

int	deal_key(int k, t_fdf *data)
{
	if (is_key(k))
	{
		if (k == 65307)
			close_win(data);
		if (k == 114 || k == 116 || k == 121 || k == 102 || k == 103 || k == 104)
			rotate_map(k, data);
		if (k == 101)
			change_size(data, 2);
		if (k == 100)
			change_size(data, -2);
		if (k == 32)
			change_projection(data);
		if (k == 113)
			updown_multi(data, 1.5);
		if (k == 97)
			updown_multi(data, 0.9);
		if (k == 119)
			updown(data, 10);
		if (k == 115)
			updown(data, -10);
		if (k == 65361 || k == 65362 || k == 65363 || k == 65364)
			move_map(k, data);
		redraw_map(data);
	}
	return (0);
}
