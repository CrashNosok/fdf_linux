#include "fdf.h"

int			set_zoom(t_fdf *data)
{
	int		height;
	int		width;
	int		max_side;

	height = data->height;
	width = data->width;
	max_side = max_val(height, width);
	if (max_side <= 20)
		return (30);
	else if (max_side <= 50)
		return (20);
	else if (max_side <= 100)
		return (7);
	else
		return (4);
	return (1);
}

int			find_max_z(t_fdf *data, int z)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			z = max_val(z, data->z_matrix[i][j]);
			j++;
		}
		i++;
	}
	return (z);
}

int			find_min_z(t_fdf *data, int z)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			z = min_val(z, data->z_matrix[i][j]);
			j++;
		}
		i++;
	}
	return (z);
}

int			get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		ft_error("file does not exist1");
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int			get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}
