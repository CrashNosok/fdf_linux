#include "fdf.h"

int			take_color(char *str)
{
	int		i;
	int		color;

	color = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] && str[i + 2] &&
			str[i + 1 == '0' && str[i + 2] == 'x'])
		{
			i += 3;
			color = ft_atoi_base((str + i), 16);
			return (color);
		}
		i++;
	}
	return (color);
}

void		fill_matrix(int *z_line, int *colors, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		colors[i] = take_color(nums[i]);
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i++]);
	}
	free(nums[i]);
	free(nums);
}

void		read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], data->colors[i], line);
		free(line);
		line = NULL;
		i++;
	}
	data->max_z = find_max_z(data, 0);
	data->min_z = find_min_z(data, 0);
	free(line);
	close(fd);
}
