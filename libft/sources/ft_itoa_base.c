#include "libft.h"

static int			ft_memory(int val, int base)
{
	int i;

	i = 0;
	if (val < 0 && base == 10)
		i++;
	while (val != 0)
	{
		val = val / base;
		i++;
	}
	return (i);
}

static char			rem_leter(int rem)
{
	if (rem >= 10 && rem <= 15)
		return (rem + 55);
	else
		return (rem + '0');
}

char				*ft_itoa_base(int value, int base)
{
	char	*str;
	int		i;
	int		mem;

	i = 1;
	if (value < 0 && base == 10)
		return (ft_itoa(value));
	if (value < 0)
		value = value * (-1);
	str = NULL;
	mem = ft_memory(value, base);
	str = (char*)malloc(sizeof(char) * (mem + 1));
	str[mem] = '\0';
	while (value != 0)
	{
		str[mem - i] = rem_leter(value % base);
		value = value / base;
		i++;
	}
	return (str);
}
