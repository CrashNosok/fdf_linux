#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "minilibx/mlx.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int			**colors;
	int			zoom;
	int			shift_x;
	int			shift_y;
	int			win_x;
	int			win_y;
	int			is_isometric;
	int			max_z;
	int			min_z;
	float		angle;
	float		x_angle;
	float		y_angle;
	float		z_angle;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

typedef struct	s_coords
{
	float		x;
	float		y;
	int			z;
	int			color;
}				t_coords;

int				is_key(int key);
void			redraw_map(t_fdf *data);
void			close_win(t_fdf *data);
void			rotate_map(int key, t_fdf *data);
void			change_size(t_fdf *data, float koef);
void			change_projection(t_fdf *data);
void			updown_multi(t_fdf *data, float koef);
void			updown(t_fdf *data, float koef);
void			move_map(int key, t_fdf *data);
int				deal_key(int key, t_fdf *data);
int				set_zoom(t_fdf *data);
int				find_max_z(t_fdf *data, int z);
int				find_min_z(t_fdf *data, int z);
int				get_height(char *file_name);
int				get_width(char *file_name);
void			create_arrays(t_fdf *data);
void			fill_color_array(t_fdf *data);
void			fill_z_array(t_fdf *data);
void			set_default(char *file_name, t_fdf *data);
void			isometric(float *x, float *y, int z, double a);
void			prepare_coords(t_coords *coords, int x, int y, t_fdf *data);
void			bresenham(t_coords coord_1, t_coords coord_2, t_fdf *data);
void			draw(t_coords *coord_1, t_coords *coord_2, t_fdf *data);
double			percent(int start, int end, int current);
int				get_default_color(int y, int x, int z, t_fdf *map);
int				get_light(int start, int end, double percentage);
int				get_color(t_coords current, t_coords start,
				t_coords end, t_coords delta);
int				take_color(char *str);
void			fill_matrix(int *z_line, int *colors, char *line);
void			read_file(char *file_name, t_fdf *data);
void			rotate_x(float *y, int *z, float angle);
void			rotate_y(float *x, int *z, float angle);
void			rotate_z(float *x, float *y, float angle);
void			ft_error(char *str);
int				ft_wdcounter(char const *str, char c);
int				max_val(int a, int b);
int				min_val(int a, int b);
int				mod(int a);
int				miss_hex(char *str);
int				check_line(char *str);
int				card_validation(char *file_name);
#endif
