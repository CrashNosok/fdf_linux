#include "fdf.h"

void		rotate_x(float *y, int *z, float angle)
{
	float	prev_y;

	prev_y = *y;
	*y = *y * cos(angle) + *z * sin(angle);
	*z = -prev_y * sin(angle) + *z * cos(angle);
}

void		rotate_y(float *x, int *z, float angle)
{
	float	prev_x;

	prev_x = *x;
	*x = *x * cos(angle) + *z * sin(angle);
	*z = -prev_x * sin(angle) + *z * cos(angle);
}

void		rotate_z(float *x, float *y, float angle)
{
	float	prev_x;

	prev_x = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = prev_x * sin(angle) + *y * cos(angle);
}
