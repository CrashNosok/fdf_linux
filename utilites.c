#include "fdf.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

int		ft_wdcounter(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int		max_val(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		min_val(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		mod(int a)
{
	if (a > 0)
		return (a);
	return (a * -1);
}
