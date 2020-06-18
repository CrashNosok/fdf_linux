#include "libft.h"

static int		ft_memory(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		i++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int nbr)
{
	char	*str;
	int		mem;
	int		i;

	i = 1;
	mem = ft_memory(nbr);
	if (!(str = malloc(sizeof(char) * (mem + 1))))
		return (0);
	str[mem] = '\0';
	str[0] = '0';
	if (!nbr)
		return (str);
	else if (nbr < 0)
	{
		str[0] = '-';
		str[mem - i++] = (nbr % 10) * (-1) + '0';
		nbr = nbr / 10 * (-1);
	}
	while (nbr != 0)
	{
		str[mem - i++] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}
