#include "fdf.h"

int				close_cross(void *param)
{
	(void)param;
	exit(0);
}

int				main(int argc, char **argv)
{
	t_fdf		*data;
	t_coords	coord_1;
	t_coords	coord_2;

	if (argc != 2)
		ft_error("wrong number of arguments");
	if (!card_validation(argv[1]))
		ft_error("card is not valid");
	data = (t_fdf*)malloc(sizeof(t_fdf));
	set_default(argv[1], data);
	read_file(*++argv, data);
	draw(&coord_1, &coord_2, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	// mlx_hook(data->win_ptr, 2, 0, deal_key, data);
	// mlx_hook(data->win_ptr, 17, 0, close_cross, data);
	mlx_loop(data->mlx_ptr);
}
