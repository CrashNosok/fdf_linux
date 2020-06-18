#include "fdf.h"

int	deal_key(int k, t_fdf *data)
{
	if (is_key(k))
	{
		if (k == 53)
			close_win(data);
		if (k == 15 || k == 17 || k == 16 || k == 3 || k == 5 || k == 4)
			rotate_map(k, data);
		if (k == 14)
			change_size(data, 2);
		if (k == 2)
			change_size(data, -2);
		if (k == 49)
			change_projection(data);
		if (k == 12)
			updown_multi(data, 1.5);
		if (k == 0)
			updown_multi(data, 0.9);
		if (k == 13)
			updown(data, 10);
		if (k == 1)
			updown(data, -10);
		if (k == 123 || k == 126 || k == 124 || k == 125)
			move_map(k, data);
		redraw_map(data);
	}
	return (0);
}
