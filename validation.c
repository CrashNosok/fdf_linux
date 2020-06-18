#include "fdf.h"

int			miss_hex(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] >= 'A' && str[i] <= 'F')
		i++;
	if (i > 7)
		ft_error("int overflow on map");
	return (i);
}

int			check_line(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			if (str[i - 1] && (str[i - 1] > '9' || str[i - 1] < '0'))
				return (0);
			else if (ft_strncmp(str + i, ",0x", 3))
				return (0);
			else
			{
				i += 3;
				i += miss_hex(str + i);
			}
		}
		else if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' ||
					str[i] > 'F') && str[i] != ' ' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int			card_validation(char *file_name)
{
	int		fd;
	int		rd;
	int		width;
	char	buf[10];
	char	*line;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		ft_error("file does not exist 2");
	if ((rd = read(fd, buf, 0)) < 0)
		ft_error("can not read a directory");
	line = NULL;
	get_next_line(fd, &line);
	if (!check_line(line))
		return (0);
	width = ft_wdcounter(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		if (!check_line(line) || (width != ft_wdcounter(line, ' ')))
			return (0);
		free(line);
	}
	free(line);
	return (1);
}
